//
//  RightTriangle.hpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#ifndef RightTriangle_hpp
#define RightTriangle_hpp

#include <stdio.h>
#include "Shape.hpp"
#include "Triangle.hpp"

using std::string;

class RightTriangle: public Triangle {
public:
    // CONSTRUCTOR
    RightTriangle(size_t, char = '*', string = "Ladder");
    
    // DESTRUCTOR
    virtual ~RightTriangle();
    
    // SETTERS
    virtual void setHeight(const size_t&) override;
    virtual void setWidth(const size_t&) override;

    // AREA & PERIMETER FUNCTIONS
    virtual double gPerimeter() override; // returns the right triangle's geometric perimeter
    virtual double tArea() override; // returns the right triangle's textual area, which is the number of characters that form the textual image of the right triangle
    virtual double tPerimeter() override; // returns the right triangle's textual perimeter, which is the number of characters on the borders of the textual image of the right triangle

    // DRAW FUNCTION
    virtual Canvas draw() const override; // draws a textual image of the right triangle on a Canvas object using the shape's pen character
};
#endif /* RightTriangle_hpp */
