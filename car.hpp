#include <string>
#include <iomanip>
#include <iostream>

class Car
{
public:
    
    Car(std::string car_make, int max_speed) : m_speed(max_speed),
                                               m_make(car_make)
    {
       
        if (max_speed > 0)
        {
            m_time = 5 + ((1 / (float)max_speed) * 100);
        }
        else
        {
            m_time = -1;
        }
    }

    
    void drive()
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(2); 
        std::cout << "The car make " << m_make << " goes from 0 to 60 in: " << m_time << " seconds. With a max speed of " << m_speed << "km/h" << std::endl;
    }

private:
    float m_time;
    int m_speed;
    std::string m_make;
};