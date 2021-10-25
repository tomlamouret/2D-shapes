//
//  Canvas.cpp
//  COMP5421_A4
//
//  Created by Tom Lamouret on 2021-07-29.
//

#include "Canvas.hpp"
#include <iostream>

using std::string;
using std::cout;

bool Canvas::check(size_t r, size_t c) const {return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();}; // validates row r and column c

void Canvas::resize(size_t rows, size_t cols) { // resizes this Canvas’s dimensions
    for (auto& grid_row : grid) grid_row.resize(cols, ' ');
    grid.resize(rows, std::vector<char>(cols, ' '));
};

Canvas::Canvas(size_t rows, size_t columns, char fillChar): grid{vector<vector<char>>(rows, vector<char>(columns, fillChar))} {}; // creates this canvas’s (rows x columns) grid filled with blank characters
size_t Canvas::getRows() const {return grid.size();}; // returns height
size_t Canvas::getColumns() const {return grid[0].size();}; // returns width

Canvas Canvas::flip_horizontal() const { // flips this canvas horizontally
    Canvas flipped{grid.size(), grid[0].size()};
    for (size_t r = 0; r < grid.size(); ++r) {
        for (size_t c = 0, i = grid[0].size() - 1; c < grid[0].size(); ++c, --i) {
            flipped.put(r, i, grid[r][c]);
        }
    }
    return flipped;
};

Canvas Canvas::flip_vertical() const { // flips this canvas vertically
    Canvas flipped{grid.size(), grid[0].size()};
    for (size_t r = 0, i = grid.size() - 1; r < grid.size(); ++r, --i) {
        for (size_t c = 0; c < grid[0].size(); ++c) {
            flipped.put(i, c, grid[r][c]);
        }
    }
    return flipped;
};

void Canvas::print(ostream& sout) const { // prints to ostream
    for (size_t r = 0; r < grid.size(); ++r) {
        for (size_t c = 0; c < grid[0].size(); ++c) {
            sout << grid[r][c];
        }
        sout << std::endl;
    }
};
         
char Canvas::get(size_t r, size_t c) const {return grid[r][c];}; // returns char at row r and column c
void Canvas::put(size_t r, size_t c, char ch) {if (check(r, c)) grid[r][c] = ch;}; // puts ch at row r and column c; this is the only function used by a shape’s draw function; returns doing nothing if r or c is invalid

void Canvas::drawString(size_t r, size_t c, const std::string text) {  // draws text starting at row r and col c on the canvas
    for (size_t i = 0; i < text.size(); ++i) {
        put(r, c, text[i]);
        ++c;
    }
};

void Canvas::overlap(const Canvas& can, size_t r, size_t c) { // copies the non-blank characters of "can" onto the invoking canvas; maps can’s origin to row r and column c on the invoking canvas
    for (size_t r1 = 0; r1 < can.getRows(); ++r1)
        for (size_t c1 = 0; c1 < can.getColumns(); ++c1)
            if (can.get(r1, c1) != ' ') put(r+r1, c+c1, can.get(r1, c1));
};

ostream& operator<< (ostream& sout, const Canvas& f) {
    for (int r = 0; r < f.getRows(); ++r) {
        for (int c = 0; c < f.getColumns(); ++c) {
            sout << f.get(r, c);
        }
        sout << std::endl;
    }
    return sout;
}
