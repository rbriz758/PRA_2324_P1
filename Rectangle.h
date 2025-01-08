#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

using namespace std;

class Rectangle : public Shape {
protected:
    Point2D* vs; 

public:
    static const int N_VERTICES = 4;  // Número de vértices de un rectángulo

    // Constructores
    Rectangle();  // Constructor por defecto(v0,v1,v2,v3 vienen establecidos)
    Rectangle(string color, Point2D* vertices);  // Constructor con parámetros
    Rectangle(const Rectangle &r);  // Constructor de copia
   
    //Destructor 
    virtual ~Rectangle();

    
    Point2D get_vertex(int ind) const;  // Obtener un vértice
    Point2D operator[](int ind) const;  // Sobrecarga de [] devuelve elemento de ind
    virtual void set_vertices(Point2D* vertices);  // Modificar los vértices
    Rectangle& operator=(const Rectangle &r);  // Sobrecarga de = (Hacer copia segura de rectangulos)
    friend ostream& operator<<(ostream &out, const Rectangle &r);  // Sobrecarga de << 

    // Implementación de métodos virtuales puros
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual void translate(double incX, double incY) override;
    virtual void print() const override;    
private:
    static bool check(Point2D* vertices);  // Verifica si conforman un rectángulo válido
};

#endif

