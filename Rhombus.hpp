//
//  Rhombus.hpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#ifndef Rhombus_hpp
#define Rhombus_hpp

#include <stdio.h>
#include <string>
#include "Shape.hpp"
#include "Canvas.hpp"

using std::string;

class Rhombus: public Shape {
public:
    // CONSTRUCTOR
    Rhombus(size_t, char = '*', string = "Diamond");
    
    // DESTRUCTOR
    virtual ~Rhombus();
    
    // SETTERS
    virtual void setHeight(const size_t&) override;
    virtual void setWidth(const size_t&) override;

    // AREA & PERIMETER FUNCTIONS
    virtual double gArea() override; // returns the rhombus' geometric area
    virtual double gPerimeter() override; // returns the rhombus' geometric perimeter
    virtual double tArea() override; // returns the rhombus' textual area, which is the number of characters that form the textual image of the rhombus
    virtual double tPerimeter() override; // returns the rhombus' textual perimeter, which is the number of characters on the borders of the textual image of the rhombus

    // DRAW FUNCTION
    virtual Canvas draw() const override; // draws a textual image of the rhombus on a Canvas object using the shape's pen character
};
#endif /* Rhombus_hpp */
