#include "Square.h"
#include <cmath>

using namespace std;

// Constructor por defecto
Square::Square() {
    vs = new Point2D[N_VERTICES]{
        Point2D(-1, 1),
        Point2D(1, 1),
        Point2D(1, -1),
        Point2D(-1, -1)
    };
    color = "red"; 
}

// Constructor con parámetros
Square::Square(string color, Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Los vértices no conforman un cuadrado válido.");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
    this->color = color;
}

// Sobrescritura de set_vertices
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Los vértices no conforman un cuadrado válido.");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Sobrescritura de print
void Square::print() const {
    cout << "Cuadrado de color " << color << " con vértices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        cout << "(" << vs[i].x << ", " << vs[i].y << ") ";
    }
    cout << endl;
}

// Sobrecarga del operador <<
ostream& operator<<(ostream &out, const Square &square) {
    square.print();  // Usamos print() para evitar duplicidad
    return out;
}

void Square::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].translate(incX, incY);
    }
}



// Verificación de cuadrado válido
bool Square::check(Point2D* vertices) {
    double side1 = Point2D::distance(vertices[0], vertices[1]);
    double side2 = Point2D::distance(vertices[1], vertices[2]);
    double side3 = Point2D::distance(vertices[2], vertices[3]);
    double side4 = Point2D::distance(vertices[3], vertices[0]);
    
    
    return (side1 == side2) && (side2 == side3) && (side3 == side4);
}

