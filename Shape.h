#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

using namespace std;

class Shape {
protected:
    string color;

public:
    // Constructor (color rojo por defcto)
    Shape();

    // Constructor
    Shape(const string& color);

    // Obtener el color
    string get_color() const;

    // Modificar el color
    void set_color(const string& c);

    // Métodos virtuales puros
    virtual double area() const = 0; //Obtiene el area
    virtual double perimeter() const = 0; //Obtiene el perimetro
    virtual void translate(double incX, double incY) = 0; //Muevo la figura
    virtual void print() const = 0; //Imprime informacion basica por pantalla

    // Virtual destructor 
    virtual ~Shape() = default;
};

#endif

