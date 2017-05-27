// this program subscribes to turtle1/pose and shows its messages on the screen
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <iomanip>

// a callback function
void poseMessageReceived(const turtlesim::Pose &msg) {
	ROS_INFO_STREAM(std::setprecision(2) << std::fixed <<
				"position=(" << msg.x << msg.y << ")" << " direction=" << msg.theta);
}

int main(int argc, char ** argv) {
	ros::init(argc, argv, "subscribe_to_pose");
	ros::NodeHandle nh;
	
	// create a subscriber object
	ros::Subscriber sub = nh.subscribe("turtle1/pose", 1000, &poseMessageReceived);

	// let ROS take over
	ros::spin();
}
