//
//  Shape.cpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#include <typeinfo>
#include "Shape.hpp"

using std::to_string;

int Shape::counter_id = 1;

// CONSTRUCTOR
Shape::Shape(size_t height, size_t width, char pen, string name): height{height}, width{width}, pen{pen}, name{name}, id{counter_id} {++counter_id;};

// DESTRUCTOR
Shape::~Shape() {};

// TO STRING
string Shape::toString() { // returns a string representation of the this shape
    return "Shape Information"
           "\n-----------------"
           "\nid:                  " + to_string(id) +
           "\nShape name:          " + name +
           "\nPen character:       " + pen +
           "\nHeight:              " + to_string(height) +
           "\nWidth:               " + to_string(width) +
           "\nTextual area:        " + to_string(tArea()) +
           "\nGeometric area:      " + to_string(gArea()) +
           "\nTextual perimeter:   " + to_string(tPerimeter()) +
           "\nGeometric perimeter: " + to_string(gPerimeter()) +
           "\nStatic type:         " + typeid(this).name() +
           "\nDynamic type:        " + typeid(*this).name();
};

// INSERTION OPERATOR OVERLOADING
ostream& operator<<(ostream& sout, Shape& shp) {return sout << shp.toString();};

// GETTERS
string Shape::getName() const {return name;};
int Shape::getId() const {return id;};
char Shape::getPen() const {return pen;};
size_t Shape::getHeight() const {return height;};
size_t Shape::getWidth() const {return width;};

//SETTERS
void Shape::setName(const string& name) {this->name = name;};
void Shape::setId(const int& id) {this->id = id;};
void Shape::setPen(const char& pc) {this->pen = pc;};
