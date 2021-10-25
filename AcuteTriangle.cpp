//
//  AcuteTriangle.cpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#include <cmath>
#include "AcuteTriangle.hpp"

// CONSTRUCTOR
AcuteTriangle::AcuteTriangle(size_t base, char pen, string name): Triangle{(base + 1) / 2, base, pen, name} {
    if (base % 2 == 0) {
        setHeight((base + 2) / 2);
        setWidth(base + 1);
    }
};

// DESTRUCTOR
AcuteTriangle::~AcuteTriangle() {};

// SETTERS
void AcuteTriangle::setHeight(const size_t& height) {
    this->height = height;
    width = 2 * height - 1;
};

void AcuteTriangle::setWidth(const size_t& base) {
    width = base;
    height = (base + 1) / 2;
};

// AREA & PERIMETER FUNCTIONS
double AcuteTriangle::gPerimeter() {return getWidth() + sqrt(getWidth()*getWidth() + 4 * getHeight()*getHeight());}; // returns the acute triangle's geometric perimeter
double AcuteTriangle::tArea() {return getHeight() * getHeight();}; // returns the acute triangle's textual area, which is the number of characters that form the textual image of the acute triangle
double AcuteTriangle::tPerimeter() {return 4 * (getHeight() - 1);}; // returns the acute triangle's textual perimeter, which is the number of characters on the borders of the textual image of the acute triangle

// DRAW FUNCTION
Canvas AcuteTriangle::draw() const { // draws a textual image of the acute triangle on a Canvas object using the shape's pen character
    Canvas can{getHeight(), getWidth()};
    for (size_t r = 0; r < getHeight(); ++r) {
        size_t numPen = 2 * r + 1;
        size_t numSpaces = (getWidth() - numPen) / 2;
        for (size_t c = 0; c < getWidth(); ++c) {
            if (c >= numSpaces && numPen > 0) {
                can.put(r, c, getPen());
                --numPen;
            }
        }
    }
    return can;
};

