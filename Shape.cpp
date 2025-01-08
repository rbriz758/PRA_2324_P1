#include "Shape.h"
#include <stdexcept>

using namespace std;

Shape::Shape() : color("red") {}

Shape::Shape(const string& c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw invalid_argument("Color inválido: " + c);
    }
    color = c;
}

string Shape::get_color() const {
    return color;
}

void Shape::set_color(const string& c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw invalid_argument("Color inválido: " + c);
    }
    color = c;
}

