#include <ros/ros.h>
#include <boost/thread/thread.hpp>
#include <Eigen/Dense>

#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <tf/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>

typedef Eigen::Matrix<float, 6, 1> Vector6f;
#define MYDEG2RAD(x) (3.14159265358979323846*x)/180.0f
#define MYRAD2DEG(x) (180.0f*x)/3.14159265358979323846

class class_name{
public:
	class_name(const ros::NodeHandle& nh,
             const ros::NodeHandle& nh_private): //initialize here
		nh_(nh),
    nh_private_(nh_private),
    latch_topics_(true) //not sure if we have to latch 
    //if using message filter, should be initialized here
	{
		setParametersFromROS();
  	subscribe();
  	advertiseServices();
  	advertisePublishers();
	}
	void class_name::setParametersFromROS(){
		nh_private_.param("tf_frame", world_frame_, world_frame_); //here how to read param from launch file: param name, parameter of param, default value

	}
	void class_name::subscribe(){
		topic_sub_ = nh_.subscribe("name of subscribed topic", 1, &class_name::topic_function_CB, this);
	}
	void class_name::advertiseServices(){
		service_name_ = nh_private_.advertiseService("service_name", 1, &class_name::service_function_CB, this);
	}
	void class_name::advertisePublishers(){
		name_nod_pub = nh_private_.advertise<messge_type>("node_name", 1, latch_topics_);
	}
	void class_name::topic_function_CB(const messagetype::ConstPtr& incomming_message){
		//process message
	}
	bool class_name::service_function_CB(std_srvs::Empty::Request& request,
                                       std_srvs::Empty::Response& response){
		//do your request here
	}
	
private:
	ros::NodeHandle nh_,nh_private_;
	bool latch_topics_;
protected:	
};
