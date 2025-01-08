#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D {
public:
    double x;  
    double y;  

    // Constructor
    Point2D(double x = 0, double y = 0);

    //Calcular Distancia entre 2 puntos
    static double distance(const Point2D& a, const Point2D& b);
    
    //Método translate
    void translate(double incX, double incY);

    //Comprobar si 2 puntos son iguales
    friend bool operator==(const Point2D& a, const Point2D& b);

    //Comprobar si 2 puntos son diferentes
    friend bool operator!=(const Point2D& a, const Point2D& b);

    //Imprimir Punto
    friend std::ostream& operator<<(std::ostream& out, const Point2D& p);
};

#endif

