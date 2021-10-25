//
//  RightTriangle.cpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#include <cmath>
#include "RightTriangle.hpp"

// CONSTRUCTOR
RightTriangle::RightTriangle(size_t base, char pen, string name): Triangle{base, base, pen, name} {};

// DESTRUCTOR
RightTriangle::~RightTriangle() {};

// SETTERS
void RightTriangle::setHeight(const size_t& base) {height = width = base;};
void RightTriangle::setWidth(const size_t& base) {width = height = base;};

// AREA & PERIMETER FUNCTIONS
double RightTriangle::gPerimeter() {return (2 + sqrt(2)) * getHeight();}; // returns the right triangle's geometric perimeter
double RightTriangle::tArea() {return getHeight() * (getHeight() + 1) / 2;}; // returns the right triangle's textual area, which is the number of characters that form the textual image of the right triangle
double RightTriangle::tPerimeter() {return 3 * (getHeight() - 1);}; // returns the right triangle's textual perimeter, which is the number of characters on the borders of the textual image of the right triangle

// DRAW FUNCTION
Canvas RightTriangle::draw() const { // draws a textual image of the right triangle on a Canvas object using the shape's pen character
    Canvas can{getHeight(), getWidth()};
    for (size_t r = 0; r < getHeight(); ++r){
        for (size_t c = 0; c < getWidth(); ++c){
            if(c <= r) can.put(r, c, getPen());
        }
    }
    return can;
};
