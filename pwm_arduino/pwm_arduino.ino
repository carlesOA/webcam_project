#include "Arduino.h"
#include <Servo.h> 
#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle  nh;
int y,x;
int b = 90;
float m = -9/6;
Servo servo;

void servo_cb( const std_msgs::Int32& cmd_msg)
{  
  x=cmd_msg.data;
  y=((m*x)+b);
  
  if (y < 0) y=0;
   
  if (y > 180) y=180;
  
  servo.write(y); //set servo angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}


ros::Subscriber<std_msgs::Int32> sub("pid_publi", servo_cb);

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  
  servo.attach(9); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}
