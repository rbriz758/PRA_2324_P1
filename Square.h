#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdexcept>
#include "Rectangle.h"

using namespace std;

class Square : public Rectangle {
public:
    // Constructores
    Square();  // Constructor por defecto
    Square(string color, Point2D* vertices);  // Constructor con parámetros

    // Sobrescritura de métodos
    void set_vertices(Point2D* vertices) override;  // Modificar los vértices (sobrescrito)
    virtual void print() const override;  // Imprime información del cuadrado

    friend ostream& operator<<(ostream &out, const Square &square);
    //Funcion añadida  por la clase Drawing
    virtual void translate(double incX, double incY) override;

private:
    static bool check(Point2D* vertices);  // Verifica si los vértices conforman un cuadrado válido
};

#endif

