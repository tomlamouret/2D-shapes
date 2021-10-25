//
//  AcuteTriangle.hpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#ifndef AcuteTriangle_hpp
#define AcuteTriangle_hpp

#include <stdio.h>
#include "Shape.hpp"
#include "Triangle.hpp"

using std::string;

class AcuteTriangle: public Triangle {
public:
    // CONSTRUCTOR
    AcuteTriangle(size_t, char = '*', string = "Wedge");
    
    // DESTRUCTOR
    virtual ~AcuteTriangle();
    
    // SETTERS
    virtual void setHeight(const size_t&) override;
    virtual void setWidth(const size_t&) override;

    // AREA & PERIMETER FUNCTIONS
    virtual double gPerimeter() override; // returns the acute triangle's geometric perimeter
    virtual double tArea() override; // returns the acute triangle's textual area, which is the number of characters that form the textual image of the acute triangle
    virtual double tPerimeter() override; // returns the acute triangle's textual perimeter, which is the number of characters on the borders of the textual image of the acute triangle

    // DRAW FUNCTION
    virtual Canvas draw() const override; // draws a textual image of the acute triangle on a Canvas object using the shape's pen character
};
#endif /* AcuteTriangle_hpp */
