#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include "Point2D.h"

using namespace std; 

class Circle : public Shape {

private:
    Point2D center;
    double radius;

public:
    // Constructor por defecto(color por defecto, centro(0,0) y radio 1)
    Circle();

    // Constructor con parámetros
    Circle(string color, Point2D center, double radius);

    // Métodos consultores
    Point2D get_center() const; //Obtiene centro
    double get_radius() const; //Obtiene radio

    // Métodos modificadores
    void set_center(Point2D p); //Modifica centro
    void set_radius(double r); //Modifica radio

    
    double area() const override; //Calucla area
    double perimeter() const override; //Calcula perimetro
    void translate(double incX, double incY) override; //Translada la figura
    void print() const override; //Imprime informacion basica del circulo

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream &out, const Circle &c);
};

#endif

