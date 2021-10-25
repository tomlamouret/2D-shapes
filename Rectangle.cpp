//
//  Rectangle.cpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#include <string>
#include "Rectangle.hpp"

using std::string;

// CONSTRUCTOR
Rectangle::Rectangle(size_t height, size_t width, char pen, string name): Shape{height, width, pen, name} {};

// DESTRUCTOR
Rectangle::~Rectangle() {};

// SETTERS
void Rectangle::setHeight(const size_t& height) {this->height = height;};
void Rectangle::setWidth(const size_t& width) {this->width = width;};

// AREA & PERIMETER FUNCTIONS
double Rectangle::gArea() {return getHeight() * getWidth();}; // returns the rectangle's geometric area
double Rectangle::gPerimeter() {return 2 * (getHeight() + getWidth());}; // returns the rectangle's geometric perimeter
double Rectangle::tArea() {return getHeight() * getWidth();}; // returns the rectangle's textual area, which is the number of characters that form the textual image of the rectangle
double Rectangle::tPerimeter() {return 2 * (getHeight() + getWidth()) - 4;}; // returns the rectangle's textual perimeter, which is the number of characters on the borders of the textual image of the rectangle

// DRAW FUNCTION
Canvas Rectangle::draw() const { // draws a textual image of the rectangle on a Canvas object using the shape's pen character
    Canvas can {getHeight(), getWidth()};
    for (int r = 0; r < getHeight(); ++r) {
        for (int c = 0; c < getWidth(); ++c) {
            can.put(r, c, getPen());
        }
    }
    return can;
};
