Header header

#middle contact link number
int32 centerContactLink

#normals
geometry_msgs/Vector3[] contact_normals

#forces
geometry_msgs/Vector3[] contact_tangents

#positions
geometry_msgs/Point[] contact_positions

#links in contact
int32[] link_numbers

#side of contact
string[] contact_sides
