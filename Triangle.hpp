//
//  Triangle.hpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include "Shape.hpp"

class Triangle: public Shape {
protected:
    // CONSTRUCTOR
    Triangle(size_t, size_t, char, string);
public:
    // DESTRUCTOR
    virtual ~Triangle();

    // AREA FUNCTION
    virtual double gArea() override; // returns the triangle's geometric area
};
#endif /* Triangle_hpp */
