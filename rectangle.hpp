#include <iostream>


class Rectangle
{
public:
   
    Rectangle(int width, int height) : m_width(width),  
                                       m_height(height) 
    {
        std::cout << "Constructor is being executed. Params: " << m_width << " and " << m_height << std::endl;
    }

  
    int area()
    {
        return m_width * m_height;
    }

private:
    int m_width, m_height;
};