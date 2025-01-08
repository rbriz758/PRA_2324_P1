#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "List.h"
#include "ListArray.h"

using namespace std;

class Drawing {
private:
    List<Shape*>* shapes;

public:
    // Constructor
    Drawing();

    // Destructor
    ~Drawing();

    // Añade figura al frente del dibujo
    void add_front(Shape* shape);

    // Añade una figura al fondo del dibujo
    void add_back(Shape* shape);

    // Muestra información de todas las figuras dibujadas
    void print_all();

    // Calcula el área de todos los círculos
    double get_area_all_circles();

    // Mueve todos los cuadrados
    void move_squares(double incX, double incY);
};

#endif

