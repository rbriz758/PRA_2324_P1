#include "Circle.h"
#include <cmath> 

using namespace std; 

// Constructor por defecto
Circle::Circle() : Shape("red"), center(Point2D(0, 0)), radius(1) {}

// Constructor 
Circle::Circle(string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

// Métodos consultores
// centro
Point2D Circle::get_center() const {
    return center;
}
//Radio
double Circle::get_radius() const {
    return radius;
}

// Métodos modificadores
// centro
void Circle::set_center(Point2D p) {
    center = p;
}
//radio
void Circle::set_radius(double r) {
    radius = r;
}

//Implementación del área
double Circle::area() const {
    return M_PI * pow(radius, 2);
}

//Implementación del perímetro
double Circle::perimeter() const {
    return 2 * M_PI * radius; 
}

//Traslación
void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

//Implementación del método print
void Circle::print() const {
    cout << "Circle: center(" << center.x << ", " << center.y << "), radius " << radius << ", color " << color << endl;
}

// Sobrecarga del operador <<
ostream& operator<<(ostream &out, const Circle &c) {
    out << "Circle: center(" << c.center.x << ", " << c.center.y << "), radius " << c.radius << ", color " << c.color;
    return out;
}

