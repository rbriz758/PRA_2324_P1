#include "Rectangle.h"
#include <cmath> 

using namespace std;

// Constructor por defecto
Rectangle::Rectangle() {
    vs = new Point2D[N_VERTICES]{
        Point2D(-1, 0.5),
        Point2D(1, 0.5),
        Point2D(1, -0.5),
        Point2D(-1, -0.5)
    };
    color = "red";
}

// Constructor con parámetros
Rectangle::Rectangle(string color, Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Los vértices no conforman un rectángulo válido.");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
    this->color = color;
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
    color = r.color;
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs; 
}

// Obtener un vértice
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw out_of_range("Índice fuera del rango de vértices.");
    }
    return vs[ind];
}

// Sobrecarga de []
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Verificar si los vértices conforman un rectángulo válido
bool Rectangle::check(Point2D* vertices) {
    double side1 = Point2D::distance(vertices[0], vertices[1]);
    double side2 = Point2D::distance(vertices[1], vertices[2]);
    double side3 = Point2D::distance(vertices[2], vertices[3]);
    double side4 = Point2D::distance(vertices[3], vertices[0]);

    
    return (side1 == side3) && (side2 == side4);
}

// Modificar los vértices
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Los vértices no conforman un rectángulo válido.");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Sobrecarga de =
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        delete[] vs; 
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = r.vs[i];
        }
        color = r.color;
    }
    return *this;
}

// Sobrecarga de <<
ostream& operator<<(ostream &out, const Rectangle &r) {
    out << "Rectángulo de color " << r.color << " con vértices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << "(" << r.vs[i].x << ", " << r.vs[i].y << ") ";
    }
    return out;
}

double Rectangle::area() const {
    double side1 = Point2D::distance(vs[0], vs[1]);
    double side2 = Point2D::distance(vs[1], vs[2]);
    return side1 * side2;
}

double Rectangle::perimeter() const {
    double side1 = Point2D::distance(vs[0], vs[1]);
    double side2 = Point2D::distance(vs[1], vs[2]);
    return 2 * (side1 + side2);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].translate(incX, incY);
    }
}

void Rectangle::print() const {
    cout << "Rectángulo de color " << color << " con vértices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        cout << "(" << vs[i].x << ", " << vs[i].y << ") ";
    }
    cout << endl;
}

