//
//  Canvas.hpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#ifndef Canvas_hpp
#define Canvas_hpp

#include <stdio.h>
#include <vector>
#include <ostream>

using std::vector;
using std::ostream;

class Canvas {
public:
   // all special members are defaulted because ’grid’,
   // the only data member, is self-sufficient and efficient; that is,
   // it is equipped to handle the corresponding operations efficiently
    Canvas() = default;
    virtual ~Canvas() = default;
    Canvas(const Canvas&) = default;
    Canvas(Canvas&&) = default;
    Canvas& operator=(const Canvas&) = default;
    Canvas& operator=(Canvas&&) = default;
protected:
    vector<vector<char> > grid{}; // the only data member
    bool check(size_t r, size_t c) const; // validates row r and column c
    void resize(size_t rows, size_t cols); // resizes this Canvas’s dimensions
public:
    Canvas(size_t rows, size_t columns, char fillChar = ' '); // creates this canvas’s (rows x columns) grid filled with blank characters
    
    size_t getRows() const; // returns height
    size_t getColumns() const; // returns width
    Canvas flip_horizontal() const; // flips this canvas horizontally
    Canvas flip_vertical() const; // flips this canvas vertically
    void print(ostream&) const; // prints to ostream
    char get(size_t r, size_t c) const; // returns char at row r and column c
    void put(size_t r, size_t c, char ch); // puts ch at row r and column c; this is the only function used by a shape’s draw function; returns doing nothing if r or c is invalid
    
    void drawString(size_t r, size_t c, const std::string text);  // draws text starting at row r and col c on the canvas
    
    void overlap(const Canvas& can, size_t r, size_t c); // copies the non-blank characters of "can" onto the invoking canvas; maps can’s origin to row r and column c on the invoking canvas
};
ostream& operator<< (ostream& sout, const Canvas& f);
#endif /* Canvas_hpp */
