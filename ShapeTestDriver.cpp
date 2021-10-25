#include<iostream>
#include<vector>

#include "Shape.hpp"
#include "Rhombus.hpp"
#include "Rectangle.hpp"
#include "AcuteTriangle.hpp"
#include "RightTriangle.hpp"
#include "Canvas.hpp"

using std::cout;
using std::endl;

void drawHouse();
void drawHouseElement(Canvas& can, Shape& shp, int row, int col);

int main()
{
    drawHouse();
    return 0;
}

void drawHouseElement(Canvas& house_canvas, Shape& shp, int row, int col)
{
   cout << shp << "\n=======================================\n";
   Canvas can_shape = shp.draw();
   house_canvas.overlap(can_shape, row, col);
}

// Using our four geometric shapes, draws a pattern that looks line a house
void drawHouse()
{
   int row_offset = -1;
   int col_offset = -1;

   // create a 50-row by 72-column Canvas as a host canvas
   Canvas hostCan(50, 72);
   hostCan.drawString(row_offset + 1, col_offset + 10, "a geometric house: front view");

   RightTriangle roof(20, '\\', "Right half of roof");
   Canvas roof_right_can = roof.draw();
   hostCan.overlap(roof_right_can, row_offset + 4, col_offset + 27);

   roof.setPen('/');
   Canvas roof_left_can = roof.draw().flip_horizontal();
   hostCan.overlap(roof_left_can, row_offset + 4, col_offset + 7);

   hostCan.drawString(row_offset + 23, col_offset + 8,
            "[][][][][][][][][][][][][][][][][][][]");

   Rectangle chimneyL(5, 1, '|', "left chimeny edge");
   drawHouseElement(hostCan, chimneyL, row_offset + 14, col_offset + 12);

   Rectangle chimneyR(4, 1, '|', "right chimeny edge");
   drawHouseElement(hostCan, chimneyR, row_offset + 14, col_offset + 13);

   Rectangle antenna_stem(11, 1, 'I', "antenna stem");
   drawHouseElement(hostCan, antenna_stem, row_offset + 11, col_offset + 45);

   RightTriangle antenna(5, '=', "Right antenna wing");
   Canvas antenna_Q1 = antenna.draw();
   Canvas antenna_Q2 = antenna_Q1.flip_horizontal();
   Canvas antenna_Q3 = antenna_Q2.flip_vertical();
   Canvas antenna_Q4 = antenna_Q1.flip_vertical();
   hostCan.overlap(antenna_Q3, row_offset + 11, col_offset + 40);
   hostCan.overlap(antenna_Q4, row_offset + 11, col_offset + 46);

   Rectangle wall(18, 1, '[', "vertical left and right brackets");
   drawHouseElement(hostCan, wall, row_offset + 24, col_offset + 8);
   drawHouseElement(hostCan, wall, row_offset + 24, col_offset + 44);

   wall.setPen(']'); // use the same wall shape
   drawHouseElement(hostCan, wall, row_offset + 24, col_offset + 9);
   drawHouseElement(hostCan, wall, row_offset + 24, col_offset + 45);

   Rectangle line(1, 66, '-', "horizontal lines depicting the ground");
   for (size_t c = 1; c <= 6; c++)
   {
      drawHouseElement(hostCan, line, row_offset + 40 + c, col_offset + 7 - c);
   }
   hostCan.drawString(row_offset + 40, col_offset + 8,
            "[][][][][][][][][][][][][][][][][][][]");
   hostCan.drawString(row_offset + 41, col_offset + 8,
            "[][][][][][][][][][][][][][][][][][][]");

   Rectangle door_step(1, 12, '/', "door step");
   drawHouseElement(hostCan, door_step, row_offset + 39, col_offset + 21);

   Rectangle door(12, 12, '|', "door");
   drawHouseElement(hostCan, door, row_offset + 27, col_offset + 21);

   Rectangle door_edge(1, 10, '=', "door top/bottom edge");
   drawHouseElement(hostCan, door_edge, row_offset + 27, col_offset + 22);
   drawHouseElement(hostCan, door_edge, row_offset + 38, col_offset + 22);

   Rectangle door_knob(1, 1, 'O', "door knob");
   drawHouseElement(hostCan, door_knob, row_offset + 33, col_offset + 22);

   hostCan.drawString(row_offset + 26, col_offset + 25, "5421");

   Rhombus window(5, '+', "left window");
   drawHouseElement(hostCan, window, row_offset + 28, col_offset + 14);
   drawHouseElement(hostCan, window, row_offset + 28, col_offset + 35);

   Rectangle tree_trunk(5, 3, 'H', "tree trunk");
   drawHouseElement(hostCan, tree_trunk, row_offset + 36, col_offset + 60);

   AcuteTriangle leaves(7, '*', "top level leaves");
   drawHouseElement(hostCan, leaves, row_offset + 21, col_offset + 58);
   leaves.setWidth(11);
   drawHouseElement(hostCan, leaves, row_offset + 23, col_offset + 56);
   leaves.setWidth(19);
   drawHouseElement(hostCan, leaves, row_offset + 26, col_offset + 52);

   hostCan.drawString(row_offset + 13, col_offset + 11, "\\||/");
   hostCan.drawString(row_offset + 12, col_offset + 11, "_/\\_");

   // finally, reveal the house image
   cout << hostCan << "-------------------------------" << endl;
   return;
}
