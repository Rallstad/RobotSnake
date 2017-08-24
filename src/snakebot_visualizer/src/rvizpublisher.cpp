#include "rvizpublisher.h"

RVizPublisher::RVizPublisher(ros::NodeHandle rosNodeHandle, int numberOfLinks): rosNode(rosNodeHandle), numberOfLinks(numberOfLinks){
    rvizPub = rosNode.advertise<visualization_msgs::Marker>("visualization_marker", 100);

    normalsMarker.header.frame_id =
        resultantNormalsMarker.header.frame_id =
            tangentsMarker.header.frame_id =
                forcesMarker.header.frame_id =
                    allForcesMarker.header.frame_id =
                        resultantForceMarker.header.frame_id =
                            ctrlMarker.header.frame_id =
                                effortMarker.header.frame_id = "/dummy_link";
    normalsMarker.ns = "normals";
    resultantNormalsMarker.ns = "sum of normals";
    tangentsMarker.ns = "tangents";
    forcesMarker.ns = "forces";
    allForcesMarker.ns = "all forces";
        resultantForceMarker.ns = "total forces";
    ctrlMarker.ns = "control";
    effortMarker.ns = "effort";
    normalsMarker.action =
        resultantNormalsMarker.action =
            tangentsMarker.action =
                forcesMarker.action =
                    allForcesMarker.action =
                        resultantForceMarker.action =
                            ctrlMarker.action =
                                effortMarker.action = visualization_msgs::Marker::ADD;
    normalsMarker.pose.orientation.w =
        resultantNormalsMarker.pose.orientation.w =
            tangentsMarker.pose.orientation.w =
                forcesMarker.pose.orientation.w =
                    allForcesMarker.pose.orientation.w =
                        resultantForceMarker.pose.orientation.w =
                            ctrlMarker.pose.orientation.w =
                                effortMarker.pose.orientation.w = 1.0;
    normalsMarker.scale.x =
        resultantNormalsMarker.scale.x =
            tangentsMarker.scale.x =
                forcesMarker.scale.x =
                    allForcesMarker.scale.x = 0.01;
    resultantForceMarker.scale.x =
        ctrlMarker.scale.x =
            effortMarker.scale.x = 0.05;
    resultantForceMarker.scale.y =
        ctrlMarker.scale.y =
            effortMarker.scale.y = 0.10;
    normalsMarker.type =
        tangentsMarker.type =
            forcesMarker.type = visualization_msgs::Marker::LINE_LIST;
    resultantNormalsMarker.type = visualization_msgs::Marker::ARROW;
    allForcesMarker.type = visualization_msgs::Marker::LINE_STRIP;
    resultantForceMarker.type = visualization_msgs::Marker::ARROW;
    ctrlMarker.type = visualization_msgs::Marker::ARROW;
    effortMarker.type = visualization_msgs::Marker::ARROW;

    normalsMarker.id = 0;
    resultantNormalsMarker.id = 1;
    tangentsMarker.id = 2;
    forcesMarker.id = 3;
    allForcesMarker.id = 4;
    resultantForceMarker.id = 5;
    ctrlMarker.id = 6;
    effortMarker.id = 7;

    normalsMarker.color.g = 1.0;
    normalsMarker.color.a = 1.0;
    resultantNormalsMarker.color.r = 1.0;
    resultantNormalsMarker.color.g = 1.0;
    resultantNormalsMarker.color.b = 1.0;
    resultantNormalsMarker.color.a = 1.0;
    tangentsMarker.color.b = 1.0;
    tangentsMarker.color.a = 1.0;
    forcesMarker.color.b = 1.0;
    forcesMarker.color.a = 1.0;
    forcesMarker.color.r = 1.0;
    forcesMarker.color.g = 1.0;
    allForcesMarker.color.r = 1.0;
    allForcesMarker.color.a = 1.0;
    resultantForceMarker.color.r = 1.0;
    resultantForceMarker.color.g = 1.0;
    resultantForceMarker.color.b = 1.0;
    resultantForceMarker.color.a = 1.0;
    ctrlMarker.color.r = 1.0;
    ctrlMarker.color.g = 1.0;
    ctrlMarker.color.b = 1.0;
    ctrlMarker.color.a = 1.0;
    effortMarker.color.r = 1.0;
    effortMarker.color.g = 1.0;
    effortMarker.color.a = 1.0;
}

void RVizPublisher::publishToRViz(){
    //cout << "publishToRviz" << endl;
    updateMarkers();
    //cout << "updated markers" << endl;
    rvizPub.publish(normalsMarker);
    //rvizPub.publish(resultantNormalsMarker);
    rvizPub.publish(tangentsMarker);
    rvizPub.publish(forcesMarker);
    rvizPub.publish(allForcesMarker);
    rvizPub.publish(resultantForceMarker);
    rvizPub.publish(ctrlMarker);
    rvizPub.publish(effortMarker);
}

void RVizPublisher::updateMarkers(){
    //cout << "updateMarkers" << endl;
    clearMarkerPointData();
    //cout << "maker point data cleared" << endl;
    normalsMarker.header.stamp =
        resultantNormalsMarker.header.stamp =
            tangentsMarker.header.stamp =
                forcesMarker.header.stamp =
                    allForcesMarker.header.stamp =
                        resultantForceMarker.header.stamp =
                            ctrlMarker.header.stamp =
                                effortMarker.header.stamp = ros::Time::now();

    allForcesMarker.points.push_back(Vector3d(0,0,0).toPointMsg());
    resultantForceMarker.points.push_back(Vector3d(0,0,0).toPointMsg());
    resultantNormalsMarker.points.push_back(Vector3d(-0.0,-1,0).toPointMsg());

    Vector3d sumNormals(0,0,0);

    for ( int i=0; i<contacts.position.size(); i++ ) {
        normalsMarker.points.push_back(contacts.position[i].toPointMsg());
        normalsMarker.points.push_back((contacts.position[i] + scaleVector(contacts.normal[i],0.3)).toPointMsg());
        sumNormals += contacts.normal[i];
        tangentsMarker.points.push_back(contacts.position[i].toPointMsg());
        tangentsMarker.points.push_back((contacts.position[i] + scaleVector(contacts.tangent[i],0.3)).toPointMsg());
        forcesMarker.points.push_back(contacts.position[i].toPointMsg());
        forcesMarker.points.push_back((contacts.position[i] + scaleVector(contacts.force[i], 0.05)).toPointMsg());
        allForcesMarker.points.push_back((Vector3d(allForcesMarker.points[i]) + scaleVector(contacts.force[i],0.05)).toPointMsg()); // This one ends up wrong I think
    }

    resultantNormalsMarker.points.push_back((Vector3d(-0.5,-0.5,0) + scaleVector(sumNormals, 1)).toPointMsg());
    resultantForceMarker.points.push_back(allForcesMarker.points[allForcesMarker.points.size()-1]);

    geometry_msgs::Point p;

    p.x = p.y = 2;
    p.z = 0;
    ctrlMarker.points.push_back(p);
    p.x += ctrlV*cos(ctrlA);
    p.y += ctrlV*sin(ctrlA);
    ctrlMarker.points.push_back(p);

    p.x = p.z = 0;
    p.y = 2;
    effortMarker.points.push_back(p);
    p.z += effort/10.;
    effortMarker.points.push_back(p);
}

void RVizPublisher::clearMarkerPointData(){
    normalsMarker.points.clear();
    resultantNormalsMarker.points.clear();
    tangentsMarker.points.clear();
    forcesMarker.points.clear();
    allForcesMarker.points.clear();
    resultantForceMarker.points.clear();
    ctrlMarker.points.clear();
    effortMarker.points.clear();

}

void RVizPublisher::getData(StateSubscriber stateSub){
    //cout << "GETTING DATA" << endl;
    snakePose = stateSub.getSnakePose();
    contacts = stateSub.getContacts();
//    for (int i = 0; i < contacts.normal.size(); i++){
//        cout << "normals:" << endl;
//        cout << contacts.normal[i].getX() << endl;
//    }
    ctrlA = stateSub.getCtrlA();
    ctrlV = stateSub.getCtrlV();
    propulsionJoint = stateSub.getPropulsionJoint();
    effort = stateSub.getEffort();
}
