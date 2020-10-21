#include <chrono>
#include <iostream>
#include <ros/ros.h>

class Timer
{
    public:
        Timer(){
        }
        ~Timer(){
            // Stop();
        }
        void Start(std::string proc){
            process_ = proc;
            m_StartTimepoint =  std::chrono::high_resolution_clock::now();
        }

        void Stop(){
            auto endTimePoint = std::chrono::high_resolution_clock::now();

            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
            auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
        
            auto duration = stop - start;
            double ms = duration * 0.001;

            ROS_INFO("Process %s took duration: %f ms", process_.c_str(), ms);
        }
    private:
        std::string process_;
        std::chrono::time_point< std::chrono::high_resolution_clock> m_StartTimepoint;
};
