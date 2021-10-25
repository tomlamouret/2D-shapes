//
//  Shape.hpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Canvas.hpp"

using std::string;
using std::ostream;

class Shape {
protected:
    // ATTRIBUTES
    string name;
    int id; // an identity number, a unique positive integer, distinct from that of all the other shapes
    char pen; // a pen character, the single character to use when drawing the shape
    size_t height; // a height, a non-negative integer
    size_t width; // a width, a non-negative integer
    
    static int counter_id;
    
    // CONSTRUCTOR
    Shape(size_t, size_t, char, string);
    
public:
    // DESTRUCTOR
    virtual ~Shape();
    
    // TO STRING
    string toString(); // returns a string representation of the this shape
    
    // INSERTION OPERATOR OVERLOADING
    friend ostream& operator<<(ostream&, Shape&);
    
    // GETTERS
    string getName() const;
    int getId() const;
    char getPen() const;
    size_t getHeight() const;
    size_t getWidth() const;
    
    //SETTERS
    void setName(const string&);
    void setId(const int&);
    void setPen(const char&);
    virtual void setHeight(const size_t&) = 0;
    virtual void setWidth(const size_t&) = 0;
    
    // AREA & PERIMETER FUNCTIONS
    virtual double gArea() = 0; // returns the shape’s geometric area
    virtual double gPerimeter() = 0; // returns the shape’s geometric perimeter
    virtual double tArea() = 0; // returns the shape’s textual area, which is the number of characters that form the textual image of the shape
    virtual double tPerimeter() = 0; // returns the shape’s textual perimeter, which is the number of characters on the borders of the textual image of the shape
    
    // DRAW FUNCTION
    virtual Canvas draw() const = 0; // draws a textual image of the shape on a Canvas object using the shape’s pen character
};
#endif /* Shape_hpp */
