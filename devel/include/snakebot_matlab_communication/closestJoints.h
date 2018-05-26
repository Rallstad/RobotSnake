// Generated by gencpp from file snakebot_matlab_communication/closestJoints.msg
// DO NOT EDIT!


#ifndef SNAKEBOT_MATLAB_COMMUNICATION_MESSAGE_CLOSESTJOINTS_H
#define SNAKEBOT_MATLAB_COMMUNICATION_MESSAGE_CLOSESTJOINTS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace snakebot_matlab_communication
{
template <class ContainerAllocator>
struct closestJoints_
{
  typedef closestJoints_<ContainerAllocator> Type;

  closestJoints_()
    : closestjoints()  {
    }
  closestJoints_(const ContainerAllocator& _alloc)
    : closestjoints(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _closestjoints_type;
  _closestjoints_type closestjoints;




  typedef boost::shared_ptr< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> const> ConstPtr;

}; // struct closestJoints_

typedef ::snakebot_matlab_communication::closestJoints_<std::allocator<void> > closestJoints;

typedef boost::shared_ptr< ::snakebot_matlab_communication::closestJoints > closestJointsPtr;
typedef boost::shared_ptr< ::snakebot_matlab_communication::closestJoints const> closestJointsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace snakebot_matlab_communication

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'snakebot_matlab_communication': ['/home/snake/Documents/catkin_ws/src/snakebot_matlab_communication/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e42bda731c775f6815ae82d3e34de264";
  }

  static const char* value(const ::snakebot_matlab_communication::closestJoints_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe42bda731c775f68ULL;
  static const uint64_t static_value2 = 0x15ae82d3e34de264ULL;
};

template<class ContainerAllocator>
struct DataType< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "snakebot_matlab_communication/closestJoints";
  }

  static const char* value(const ::snakebot_matlab_communication::closestJoints_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32[] closestjoints\n\
";
  }

  static const char* value(const ::snakebot_matlab_communication::closestJoints_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.closestjoints);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct closestJoints_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::snakebot_matlab_communication::closestJoints_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::snakebot_matlab_communication::closestJoints_<ContainerAllocator>& v)
  {
    s << indent << "closestjoints[]" << std::endl;
    for (size_t i = 0; i < v.closestjoints.size(); ++i)
    {
      s << indent << "  closestjoints[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.closestjoints[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SNAKEBOT_MATLAB_COMMUNICATION_MESSAGE_CLOSESTJOINTS_H