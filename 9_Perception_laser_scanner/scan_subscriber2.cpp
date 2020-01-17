#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "laserscan/LaserScanner.h"

// write a ROS node as a subscriber to a laser scanner

// rosbag play laserscan_record.bag
// rosrun beginner_tutorials scan_subscriber2_cpp


using namespace std;

sensor_msgs::LaserScan _scanMsg;
ros::Subscriber scanSubscriber;

void scanCallback (sensor_msgs::LaserScan scanMessage);

int main(int argc, char **argv){

	//initialize the ROS node
	ros::init(argc, argv, "scan_subscriber_cpp");
	ros::NodeHandle n;

	//subscribe to the laser scanner topic
	scanSubscriber = n.subscribe("/scan", 10, scanCallback);

	ros::spin();
}

void scanCallback (sensor_msgs::LaserScan scanMessage){
	//_scanMsg = scanMessage;
	cout<<"minimum range: " <<LaserScanner::getMinimumRange(scanMessage)<<endl;
    cout<<"maximum range: " <<LaserScanner::getMaximumRange(scanMessage)<<endl;
    cout<<"average range: " <<LaserScanner::getAverageRange(scanMessage,0,600)<<endl;
    if (LaserScanner::isObstacleTooClose(scanMessage,0,600,0.69)==true){
        cout<<"obstacle too close"<<endl;
    }
    cout<<endl;

}