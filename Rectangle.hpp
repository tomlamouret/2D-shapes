//
//  Rectangle.hpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include <string>
#include "Shape.hpp"
#include "Canvas.hpp"

using std::string;

class Rectangle: public Shape {
public:
    // CONSTRUCTOR
    Rectangle(size_t, size_t, char = '*', string = "Rectangle");
    
    // DESTRUCTOR
    virtual ~Rectangle();
    
    // SETTERS
    virtual void setHeight(const size_t&) override;
    virtual void setWidth(const size_t&) override;
    
    // AREA & PERIMETER FUNCTIONS
    virtual double gArea() override; // returns the rectangle's geometric area
    virtual double gPerimeter() override; // returns the rectangle's geometric perimeter
    virtual double tArea() override; // returns the rectangle's textual area, which is the number of characters that form the textual image of the rectangle
    virtual double tPerimeter() override; // returns the rectangle's textual perimeter, which is the number of characters on the borders of the textual image of the rectangle

    // DRAW FUNCTION
    virtual Canvas draw() const override; // draws a textual image of the rectangle on a Canvas object using the shape's pen character
};
#endif /* Rectangle_hpp */
