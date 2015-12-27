#ifndef ROS_KALMAN_FILTER_NODE_H
#define ROS_KALMAN_FILTER_NODE_H

//std C++
#include <iostream>

//OpenCV
#include "cv.h"

//ROS headers for image I/O
#include <std_msgs/Float32MultiArray.h>

class RosKalmanFilterNode{
    protected:
        ros::NodeHandle nh_;

        //subscriber to faces detector topic
        ros::Subscriber detected_pixels;

        //publisher
        ros::Publisher kalman_msg;

        //wished process rate [hz]
        double rate_;

    protected:
        //callbacks
        void centerFacePixelsCallbacks(const std_msgs::Float32MultiArray::ConstPtr& msg);

    public:
        /** \brief Constructor
        *
        * Constructor
        *
        */
        RosKalmanFilterNode();

        /** \brief Destructor
        *
        * Destructor
        *
        */
        ~RosKalmanFilterNode();

        /** \brief Prediction x(t) & Cx(t)
         *
         * Prediction x(t) & Cx(t)
         *
         */
         void prediction();

         /** \brief Correction part kalman filter
          *
          * Correction part kalman filter
          *
          */
         void correction();

         /** \brief get distance Malanovich
          *
          * get distance Malanovich
          *
          */
         double distanceMalanovich();

         /** \brief Publish kalman msg (center face pixel predicted)
         *
         * Publish kalman msg (center face pixel predicted)
         *
         */
         void publish();

         /** \brief Returns rate_
          *
          * Returns rate_
          *
          **/
         double getRate() const;


};


#endif // ROS_KALMAN_FILTER_NODE_H
