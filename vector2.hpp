#include <iostream>
using namespace std;

class Vector2{
    private:
        float x,y;

    public:
        Vector2(float, float);
        void print();
};

Vector2::Vector2(float _x, float _y){
    x = _x;
    y = _y;
}

void Vector2::print(){
    cout << "El valor de x es " << x << " y el valor de y es " << y << endl; 
}

