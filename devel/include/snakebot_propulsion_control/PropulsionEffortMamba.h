// Generated by gencpp from file snakebot_propulsion_control/PropulsionEffortMamba.msg
// DO NOT EDIT!


#ifndef SNAKEBOT_PROPULSION_CONTROL_MESSAGE_PROPULSIONEFFORTMAMBA_H
#define SNAKEBOT_PROPULSION_CONTROL_MESSAGE_PROPULSIONEFFORTMAMBA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace snakebot_propulsion_control
{
template <class ContainerAllocator>
struct PropulsionEffortMamba_
{
  typedef PropulsionEffortMamba_<ContainerAllocator> Type;

  PropulsionEffortMamba_()
    : jointnum(0)
    , desiredtorque(0.0)  {
    }
  PropulsionEffortMamba_(const ContainerAllocator& _alloc)
    : jointnum(0)
    , desiredtorque(0.0)  {
  (void)_alloc;
    }



   typedef int32_t _jointnum_type;
  _jointnum_type jointnum;

   typedef double _desiredtorque_type;
  _desiredtorque_type desiredtorque;




  typedef boost::shared_ptr< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> const> ConstPtr;

}; // struct PropulsionEffortMamba_

typedef ::snakebot_propulsion_control::PropulsionEffortMamba_<std::allocator<void> > PropulsionEffortMamba;

typedef boost::shared_ptr< ::snakebot_propulsion_control::PropulsionEffortMamba > PropulsionEffortMambaPtr;
typedef boost::shared_ptr< ::snakebot_propulsion_control::PropulsionEffortMamba const> PropulsionEffortMambaConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace snakebot_propulsion_control

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'snakebot_propulsion_control': ['/home/snake/Documents/catkin_ws/src/snakebot_propulsion_control/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4a8b56678dbbea5f95218ac247cce854";
  }

  static const char* value(const ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4a8b56678dbbea5fULL;
  static const uint64_t static_value2 = 0x95218ac247cce854ULL;
};

template<class ContainerAllocator>
struct DataType< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >
{
  static const char* value()
  {
    return "snakebot_propulsion_control/PropulsionEffortMamba";
  }

  static const char* value(const ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
int32 jointnum\n\
float64 desiredtorque\n\
";
  }

  static const char* value(const ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.jointnum);
      stream.next(m.desiredtorque);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PropulsionEffortMamba_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::snakebot_propulsion_control::PropulsionEffortMamba_<ContainerAllocator>& v)
  {
    s << indent << "jointnum: ";
    Printer<int32_t>::stream(s, indent + "  ", v.jointnum);
    s << indent << "desiredtorque: ";
    Printer<double>::stream(s, indent + "  ", v.desiredtorque);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SNAKEBOT_PROPULSION_CONTROL_MESSAGE_PROPULSIONEFFORTMAMBA_H
