//
//  Rhombus.cpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#include "Rhombus.hpp"
#include <cmath>

// CONSTRUCTOR
Rhombus::Rhombus(size_t diagonal, char pen, string name): Shape{diagonal, diagonal, pen, name} {
    if (diagonal % 2 == 0){
        setHeight(diagonal + 1);
        setWidth(diagonal + 1);
    }
};

// DESTRUCTOR
Rhombus::~Rhombus() {};

// SETTERS
void Rhombus::setHeight(const size_t& diagonal) {height = width = diagonal;};
void Rhombus::setWidth(const size_t& diagonal) {width = height = diagonal;};

// AREA & PERIMETER FUNCTIONS
double Rhombus::gArea() {return (getHeight() * getWidth()) / 2;}; // returns the rhombus' geometric area
double Rhombus::gPerimeter() {return (2 * sqrt(2)) * 2;}; // returns the rhombus' geometric perimeter
double Rhombus::tArea() { // returns the rhombus' textual area, which is the number of characters that form the textual image of the rhombus
    double n = floor(getHeight()/2);
    return 2 * n * (n + 1) + 1;
};
double Rhombus::tPerimeter() {return 2 * (getHeight() - 1);}; // returns the rhombus' textual perimeter, which is the number of characters on the borders of the textual image of the rhombus

// DRAW FUNCTION
Canvas Rhombus::draw() const { // draws a textual image of the rhombus on a Canvas object using the shape's pen character
    Canvas can{getHeight(), getWidth()};
    size_t numSpaces = (getWidth() - 1) / 2;
    size_t numStars = 1;
    for (size_t r = 0; r < getHeight(); ++r) {
        for (size_t c = 0; c < numStars; ++c) {
            can.put(r, c + numSpaces, getPen());
        }
        if (r < getHeight() / 2){
            numSpaces -= 1;
            numStars  += 2;
        } else {
            numSpaces += 1;
            numStars  -= 2;
        }
    }
    return can;
};
