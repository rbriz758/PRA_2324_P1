#include "Drawing.h"

using namespace std;

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print(); // Imprime el print de las clases derivadas
    }
}

double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* circle = dynamic_cast<Circle*>(shapes->get(i));
        if (circle != nullptr) {
            total_area += circle->area(); // Utiliza la función area de los círculos
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* square = dynamic_cast<Square*>(shapes->get(i));
        if (square != nullptr) {
            square->translate(incX, incY); // Método translate de la clase Square
        }
    }
}

