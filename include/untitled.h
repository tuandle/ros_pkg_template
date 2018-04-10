#ifndef CLASS_NAME_H_
#define CLASS_NAME_H_

#include <ros/ros.h>

namespace CLASS_NAME_SPACE{

class class_name{
public:
	class_name(const ros::NodeHandle& nh, const ros::NodeHandle& nh_private);
	void topic_function_CB(const messagetype::ConstPtr& incomming_message);
	void service_function_CB(std_srvs::Empty::Request& request,
                           std_srvs::Empty::Response& response);
private:
	void setParametersFromROS();
  void subscribe();
  void advertiseServices();
  void advertisePublishers();

  ros::NodeHandle nh_;
  ros::NodeHandle nh_private_;

  tf::TransformListener tf_listener_;
}//end of class_name

}//end of class_name_space
#endif
