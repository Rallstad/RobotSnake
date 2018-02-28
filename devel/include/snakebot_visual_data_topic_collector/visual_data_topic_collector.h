// Generated by gencpp from file snakebot_visual_data_topic_collector/visual_data_topic_collector.msg
// DO NOT EDIT!


#ifndef SNAKEBOT_VISUAL_DATA_TOPIC_COLLECTOR_MESSAGE_VISUAL_DATA_TOPIC_COLLECTOR_H
#define SNAKEBOT_VISUAL_DATA_TOPIC_COLLECTOR_MESSAGE_VISUAL_DATA_TOPIC_COLLECTOR_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose2D.h>

namespace snakebot_visual_data_topic_collector
{
template <class ContainerAllocator>
struct visual_data_topic_collector_
{
  typedef visual_data_topic_collector_<ContainerAllocator> Type;

  visual_data_topic_collector_()
    : jointposes()  {
    }
  visual_data_topic_collector_(const ContainerAllocator& _alloc)
    : jointposes(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::geometry_msgs::Pose2D_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose2D_<ContainerAllocator> >::other >  _jointposes_type;
  _jointposes_type jointposes;




  typedef boost::shared_ptr< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> const> ConstPtr;

}; // struct visual_data_topic_collector_

typedef ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<std::allocator<void> > visual_data_topic_collector;

typedef boost::shared_ptr< ::snakebot_visual_data_topic_collector::visual_data_topic_collector > visual_data_topic_collectorPtr;
typedef boost::shared_ptr< ::snakebot_visual_data_topic_collector::visual_data_topic_collector const> visual_data_topic_collectorConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace snakebot_visual_data_topic_collector

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'snakebot_visual_data_topic_collector': ['/home/snake/Documents/catkin_ws/src/snakebot_visual_data_topic_collector/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0c6f0598a6c1c5c4f41cb8ce0c396bdf";
  }

  static const char* value(const ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0c6f0598a6c1c5c4ULL;
  static const uint64_t static_value2 = 0xf41cb8ce0c396bdfULL;
};

template<class ContainerAllocator>
struct DataType< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >
{
  static const char* value()
  {
    return "snakebot_visual_data_topic_collector/visual_data_topic_collector";
  }

  static const char* value(const ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Pose2D[] jointposes\n\
================================================================================\n\
MSG: geometry_msgs/Pose2D\n\
# This expresses a position and orientation on a 2D manifold.\n\
\n\
float64 x\n\
float64 y\n\
float64 theta\n\
";
  }

  static const char* value(const ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.jointposes);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct visual_data_topic_collector_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::snakebot_visual_data_topic_collector::visual_data_topic_collector_<ContainerAllocator>& v)
  {
    s << indent << "jointposes[]" << std::endl;
    for (size_t i = 0; i < v.jointposes.size(); ++i)
    {
      s << indent << "  jointposes[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Pose2D_<ContainerAllocator> >::stream(s, indent + "    ", v.jointposes[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SNAKEBOT_VISUAL_DATA_TOPIC_COLLECTOR_MESSAGE_VISUAL_DATA_TOPIC_COLLECTOR_H