//
//  Triangle.cpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#include "Triangle.hpp"

// CONSTRUCTOR
Triangle::Triangle(size_t height, size_t base, char pen, string name): Shape{height, base, pen, name} {};

// DESTRUCTOR
Triangle::~Triangle() {};

// AREA FUNCTION
double Triangle::gArea() {return (getHeight() * getWidth()) / 2;}; // returns the triangle's geometric area
