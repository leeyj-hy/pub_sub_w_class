#include <ros/ros.h>
#include "geometry_msgs/Twist.h"

class SubscribeAndPublish
{

    int i=0;
public:
  SubscribeAndPublish()
  {
        //퍼블리쉬 할 토픽 선언
        pub_ = n_.advertise<geometry_msgs::Twist>("/published_topic", 1);

        //섭스크라이브 할 토픽픽 선언
        sub_ = n_.subscribe("/chatter", 1, &SubscribeAndPublish::callback, this);
  }

  void callback(const find_circle::Num& input)
  {
        geometry_msgs::Twist output;
        //callback 함수에서 받은 input을 사용해서 output을 만들고 이를 pub한다.
        pub_.publish(output);
  }

private: //private으로 NodeHandle과 publisher, subscriber를 선언한다.
    ros::NodeHandle n_; 
    ros::Publisher pub_;
    ros::Subscriber sub_;
};

int main(int argc, char **argv)
{

    ros::init(argc, argv, "subscribe_and_publish");
    SubscribeAndPublish SAPObject; //클래스 객체 선언을 하게 되면 모든게 된다.
    ros::spin();
    return 0;
}