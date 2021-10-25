# 2D-shapes

**COMP 5421 Advanced Programming**

**Purpose**
• Practice fundamental object-oriented programming (OOP) concepts
• Implement an inheritance hierarchy of classes C++
• Learn about virtual functions, overriding, and polymorphism in C++
• Use two-dimensional arrays using array and vector, the two simplest container class templates in the C++ Standard Template Library (STL)
• Use modern C++ smart pointers, avoiding calls to the delete operator for good! 

**Overview**

Using simple two-dimensional geometric shapes, this assignment will give you practice with the fundamental principles of object-oriented programming (OOP).
The assignment starts by abstracting the essential attributes and operations common to the geometric shapes of interest in this assignment, namely, rhombus, rectangle, and two kinds of triangle shapes.
You will then be tasked to implement the shape abstractions using the C++ features that support encapsulation, information hiding, inheritance and polymorphism.
In addition to implementing the shape classes, you will be tasked to implement a Canvas class whose objects can be used by the shape objects to draw on.
The geometric shapes of interest in this assignment are four simple two-dimensional shapes which can be textually rendered into visually identifiable images on the computer screen; specifically: rhombus , rectangle, and two special kinds of isosceles triangles.
            
**Modeling 2D Geometric Shapes**

3.1 Common Attributes: Data

The 2D shapes of interest to us have five attributes in common. Specifically, each shape has 􏰀 a name, a string object; for example, “Book” for a rectangular shape
􏰀 an identity number, a unique positive integer, distinct from that of all the other shapes 􏰀 a pen character, the single character to use when drawing the shape
􏰀 a height, a non-negative integer 􏰀 a width, a non-negative integer
Note: here, we assume that the height and width of a shape measure, respectively, that shape’s vertical and horizontal attributes, although they may be called by a different name for different shapes; for example, both attributes for a rhombus are called “diagonal”, and the horizontal attribute of a triangle is called “base.”

3.2 Common Operations: Interface

Listed below are the services that every concrete 2D geometric object is expected to provide.

3.2.1 General Operations

1. A constructor that accepts as parameters the initial values of a shape’s height, width, pen, and name, in that order.
2. Five accessor (getter) methods, one for each attribute;
3. Two mutator (setter) methods for setting the name and pen members;
4. A toString() method that forms and returns a string representation of the this shape

3.2.2 Shape-Specific Operations

5. Two mutator (setter) methods for setting the height and width members;
6. A method to compute and return the shape’s geometric area;
7. A method to compute and return the shape’s geometric perimeter;
8. A method to compute the shape’s textual area, which is the number of characters that form the textual image of the shape;
9. A method to compute the shape’s textual perimeter, which is the number of characters on the borders of the textual image of the shape;
10. A method that draws a textual image of the shape on a Canvas object using the shape’s pen character.

4 Modeling Specialized 2D Geometric Shapes

There are several ways to classify 2D shapes, but we use the following, which is specifically designed for you to gain experience with implementing inheritance and polymorphism in C++:
 is-a
Shape
Rhombus
is-a
     Rectangle
Triangle
is-a
RightTriangle
is-a
   Figure 1: A UML class diagram showing an inheritance hierarchy specified by two abstract classes Shape and Triangle , and by four concrete classes Rectangle, Rhombus, AcuteTriangle, and RightTriangle.
Encapsulating the attributes and operations common to all shapes, class Shape must necessarily be abstract1 because the shapes it models are so general that it simply would not know how to implement the operations specified in section 3.2.2.
As a base class, Shape serves as a common interface to all classes in the inheritance hierarchy. As an abstract class, Shape makes polymorphism in C++ possible through the types Shape* and
Shape&.2
Similarly, class Triangle must be abstract, since it would have no knowledge about the specific
triangular shapes it generalizes.
Classes Rectangle, Rhombus, RightTriangle and AcuteTriangle are concrete because they each fully implement their respective interface.




6 Task1of2
Implement the Shape inheritance class hierarchy described above. It is completely up to you to decide which operations should be virtual, pure virtual, or non-virtual, provided that it satisfies a few simple requirements.
The amount of coding required for this task is not a lot as your shape classes will be small. Be sure that common behavior (shared operations) and common attributes (shared data) are pushed toward the top of your class hierarchy; for example:
6.1 Modeling 2D Triangle Shapes
6.1.1 Common Attributes
The common attributes of triangles are their heights and bases which are already being represented by height and width data members in Shape.
6.1.2 Common Operations
􏰀 A method to return a geometric area of the triangle
Note: Without knowledge about its shape, a Triangle object can compute its area based
on its height and width.
6.1.3 Type-Specific Operations
􏰀 A method to return a triangle’s height which may depend on is base 􏰀 A method to return a triangle’s width which may depend on is height 􏰀 A method to return a geometric perimeter of the triangle
Note: Without knowledge about its shape, a Triangle object is unable to compute its perimeter based on its height and width.

7
Some Examples
Sourse code
   Shape Information
-----------------
id:                  1
Shape name:          Rectangle
Pen character:       *
 Height:              5
Width:               7
Textual area:        35
Geometric area:      35.00
Textual perimeter:   20
Geometric perimeter: 24.00
 Static type:         PK5Shape
Dynamic type:        9Rectangle
    1 2 3 4
Output
1 2 3 4 5 6 7 8 9
10 11 12 13
Rectangle rect{ 5, 7 };
cout << rect.toString() << endl; // or equivalently
// cout << rect << endl;
   The call rect.toString() on line 2 of the source code generates the entire output shown. However, note that line 4 would produce the same output, as the output operator overload itself internally calls toString().
Line 3 of the output shows that rect’s ID number is 1. The ID number of the next shape will be 2, the one after 3, and so on. These unique ID numbers are generated and assigned when shape objects are first constructed.
Lines 4-5 of the output show object rect’s name and pen character, and lines 6-7 show rect’s width and height, respectively.
Now let’s see how rect’s static and dynamic types are produced on lines 12-13 of the output.
To get the name of the static type of a pointer p at runtime you use typeid(p).name(), and to get its dynamic type you use typeid(*p).name(). That’s exactly what toString() does at line 2, using this instead of p. You need to include the <typeinfo> header for this.
As you can see on lines 12-13, rect’s static type name is PK5Shape and it’s dynamic type name is 9Rectangle. The actual names returned by these calls are implementation defined. For example, the output above was generated under g++ (GCC) 10.2.0, where PK in PK5Shape means “pointer to konst const”, and 5 in 5Shape means that the name “Shape” that follows it is 5 character long.
Microsoft VC++ produces a more readable output as shown below.

  Shape Information
 -----------------
id:                  1
Shape name:          Rectangle
Pen character:       *
Height:              5
Width:               7
 Textual area:        35
Geometric area:      35.00
Textual perimeter:   20
Geometric perimeter: 24.00
Static type:         class Shape const *
 Dynamic type:        class Rectangle
     1 2 3 4
1 2 3 4 5 6 7 8 9
10 11 12 13
14 15 16 17 18
22 23 24 25 26
Rectangle rect{ 5, 7 };
cout << rect.toString() << endl; // or equivalently
// cout << rect << endl;
   Here is an example of a Rhombus object:
   Shape Information
-----------------
id:
Shape name:
Pen character:
Height:
2
Ace of diamond
v
17
 Width:               17
Textual area:        145
Geometric area:      144.50
Textual perimeter:   32
Geometric perimeter: 48.08
 Static type:         class Shape const *
Dynamic type:        class Rhombus
    Rhombus
   ace{16, ’v’, "Ace of diamond"};
// cout << ace.toString() << endl; // or, equivalently:
cout << ace << endl;
5
6 19
7 20
8 21
9
   Notice that in line 6, the supplied height 16 is invalid because it is even; to correct it, Rhombus’s constructor uses the next odd integer, 17, as the diagonal of object ace.
Again, lines 7 and 9 would produce the same output; the difference is that the call to toString() is implicit in line 9.
Here are examples of AcuteTriangle and RightTriangle shape objects.
COMP 5421/1-BB, Assignment 4, Summer 2021, page 7 of 21

  Shape Information
 -----------------
id:                  3
Shape name:          Wedge
Pen character:       *
Height:              9
Width:               17
 Textual area:        81
Geometric area:      76.50
Textual perimeter:   32
Geometric perimeter: 41.76
Static type:         class Shape const *
 Dynamic type:        class AcuteTriangle
    AcuteTriangle at{ 17 };
cout << at << endl;
 /*equivalently:
Shape *atptr = &at;
cout << *atptr << endl;
Shape &atref = at;
cout << atref << endl;
*/
  10 11 12 13 14 15 16 17 18 19 20
21 RightTriangle
22 rt{ 10, ’L’, "Carpenter’s square"
23 cout << rt << endl;
24 // or equivalently
25 // cout << rt.toString() << endl;
7.1 Polymorphic Magic
27 28 29 30 31 32 33 34 35 36 37 38 39
40 41 42
43 Shape name:
44 Pen character:
4}5;Height:
46 Width:
47 Textual area:
48 Geometric area: 49
50
51
52
Carpenter’s square
L
10
10
55 50.00
     Shape Information
-----------------
id:                  4
   Textual perimeter:   27
Geometric perimeter: 34.14
Static type:         class Shape const *
Dynamic type:        class RightTriangle
   Note that on line 22 in the source code above, rt is a regular object variable, as opposed to a pointer (or reference) variable pointing to (or referencing) an object; as such, rt cannot make polymorphic calls. That’s because in C++ the calls made by a regular object, such as rect,ace, at, and rt, to any function (virtual or not) are bound at compile time (early binding).
Polymorphic magic happens through the second argument in the calls to the output operator<< at lines 4, 9, 11, and 23. For example, consider the call cout << rt on line 23 which is equivalent to operator<<(cout, rt). The second argument in the call, rt, corresponds to the second parameter of the output operator overload:
ostream& operator<< (ostream& out, const Shape& shp);
     COMP 5421/1-BB, Assignment 4, Summer 2021, page 8 of 21

Specifically, rt in line 23 gets bound to parameter shp which is a reference and as such, can call virtual functions of Shape polymorphically. That means, the decision as to which function to invoke depends on the type of the object referenced by shp at run time (late binding).
For example, if shp references a Rhombus object, then the call shp.geoArea() binds to Rhombus::geoArea(), if shp references a Rectangle object, then shp.geoArea() binds to Rectangle::geoArea(), and so on.
However, consider rt on line 25; although rt is not a reference or a pointer, it is the invoking object in the call rt.toString() which is represented inside Shape::toString() by the this pointer, which in fact can call virtual functions of Shape (the base class) polymorphically.
7.2 Shape’s Draw Function
virtual Canvas draw() const = 0; // concrete derived classes must implement it Introduced in Shape as a pure member function, the draw() function forces concrete derived
classes to implement it.
Defining a Canvas object like so
Canvas can { getHeight(), getWidth() };
the draw function draws on can using its put members function, something like this: can.put(r, c, penChar); // write penChar in cell at row r and column c
                A Canvas object models a two-dimensional grid as abstracted in the Figure at right. The rows of the grid are parallel to the x-axis, with row numbers increasing down. The columns of the grid are parallel to the y-axis, with column numbers increasing to the right. The origin of the grid is located at the top-left grid cell (0, 0) at row 0 and column 0.
01234 0
1 2 3 4 5
y
x

7.3
Examples Continued
       v
    vvv
   vvvvv
  vvvvvvv
 vvvvvvvvv
vvvvvvvvvvv
   vvvvvvvvvvvvv
 vvvvvvvvvvvvvvv
vvvvvvvvvvvvvvvvv
 vvvvvvvvvvvvvvv
  vvvvvvvvvvvvv
 vvvvvvvvvvv
 vvvvvvvvv
  vvvvvvv
   vvvvv
    vvv
     v
     26 27 28
53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69
Canvas aceCan = ace.draw();
cout << aceCan << endl;
      *******
*******
 *******
*******
*******
    29 30 31
32 33 34 35
70 71 72 73 74
Canvas rectCan = rect.draw();
cout << rectCan << endl;
           ^
    ^^^
   ^^^^^
  ^^^^^^^
 ^^^^^^^^^
^^^^^^^^^^^
   ^^^^^^^^^^^^^
 ^^^^^^^^^^^^^^^
^^^^^^^^^^^^^^^^^
 75 76 77 78 79 80 81 82 83
   at.setPen(’^’);
Canvas atCan = at.draw();
cout << atCan << endl;

  L
 LL
LLL
LLLL
LLLLL
LLLLLL
LLLLLLL
 LLLLLLLL
LLLLLLLLL
LLLLLLLLLL
     36 37 38
84 85 86 87 88 89 90 91 92 93
94 95 96
Canvas rtCan = rt.draw();
cout << rtCan << endl;
   A Canvas object can be flipped both vertically and horizontally:
   O
OO
OOO
OOOO
OOOOO
 OOOOOO
OOOOOOO
OOOOOOOO
OOOOOOOOO
OOOOOOOOOO
    39 97
40 98
41 99
42
100 101 102 103
104 105 106 107 108 109 110 111 112 113
rt.setPen(’O’);
Canvas rtQuadrant_1 = rt.draw();
cout << rtQuadrant_1 << endl;
      O OO OOO
      OOOO
    OOOOO
   OOOOOO
  OOOOOOO
 OOOOOOOO
OOOOOOOOO
 OOOOOOOOOO
    43 44p_horizontal(); 45
Canvas rtQuadrant_2 = rtQuadrant_1.fli
cout << rtQuadrant_2 << endl;

  OOOOOOOOOO
 OOOOOOOOO
 OOOOOOOO
  OOOOOOO
   OOOOOO
    OOOOO
     OOOO
 OOO OO O
     46 47p_vertical(); 48
114 115 116 117 118 119 120 121 122 123
124 125 126 127 128 129 130 131 132 133
Canvas rtQuadrant_3 = rtQuadrant_2.fli
cout << rtQuadrant_3 << endl;
     OOOOOOOOOO
OOOOOOOOO
OOOOOOOO
OOOOOOO
OOOOOO
 OOOOO
OOOO
OOO
OO
O
     49 50p_horizontal(); 51
Canvas rtQuadrant_4 = rtQuadrant_3.fli
cout << rtQuadrant_4 << endl;
   Now, let’s create a polymorphic vector of shapes and draw them polymorphically:

  *******
 *******
*******
*******
*******
v
     vvv
   vvvvv
  vvvvvvv
 vvvvvvvvv
vvvvvvvvvvv
   vvvvvvvvvvvvv
 vvvvvvvvvvvvvvv
vvvvvvvvvvvvvvvvv
 vvvvvvvvvvvvvvv
  vvvvvvvvvvvvv
   vvvvvvvvvvv
 vvvvvvvvv
 vvvvvvv
  vvvvv
   vvv
    v
     *
   ***
  *****
 *******
*********
    ***********
  *************
 ***************
*****************
L
 LL
LLL
LLLL
LLLLL
LLLLLL
 LLLLLLL
LLLLLLLL
LLLLLLLLL
LLLLLLLLLL
  52 53 54 55 56 57 58
59 154
60 155
61 156
62 63 64 65 66 67 68 69
134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153
157 158 159 160 161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177
  // first, create a polymorphic
// vector<smart pointer to Shape>: std::vector<std::unique_ptr<Shape>> shapeVec;
// Next, add some shapes to shapeVec
shapeVec.push_back
   (std::make_unique<Rectangle>(5, 7));
shapeVec.push_back
   (std::make_unique<Rhombus>(16, ’v’, "Ace"));
shapeVec.push_back
   (std::make_unique<AcuteTriangle>(17));
shapeVec.push_back
   (std::make_unique<RightTriangle>(10, ’L’));
// now, draw the shapes in shapeVec
for (const auto& shp : shapeVec)
   cout << shp->draw() << endl;

8 Task2of2
Implement a Canvas class using the following declaration. Feel free to introduce other private member functions of your choice to facilitate the operations of the other members of the class.
1 2 3 4 5 6 7 8 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29he 30cton; 31id
32 33 34 35 36 37 38 39 40
  class Canvas
{
public:
   // all special members are defaulted because ’grid’,
   // the only data member, is self-sufficient and efficient; that is,
   // it is equipped to handle the corresponding operations efficiently
Canvas()
virtual ~Canvas()
Canvas(const Canvas&)
Canvas(Canvas&&)
Canvas& operator=(const Canvas&) = default;
= default;
= default;
= default;
= default;
   Canvas& operator=(Canvas&&)
protected:
vector<vector<char> > grid{};
bool check(int r, int c)const;
void resize(size_t rows, size_t cols); // resizes this Canvas’s dimensions
public:
// creates this canvas’s (rows x columns) grid filled with blank characters Canvas(int rows, int columns, char fillChar = ’ ’);
int getRows()const;
int getColumns()const;
Canvas flip_horizontal()const;
Canvas flip_vertical()const;
void print(ostream&) const;
char get(int r, int c) const;
void put(int r, int c, char ch);
// returns height
// returns width
// flips this canvas horizontally
// flips this canvas vertically
// prints to ostream
// returns char at row r and column c
// puts ch at row r and column c; this is t
// only function used by a shape’s draw fun
// returns doing nothing if r or c is inval
   // draws text starting at row r and col c on the canvas
   void drawString(int r, int c, const std::string text);
// copies the non-blank characters of "can" onto the invoking canvas; // maps can’s origin to row r and column c on the invoking canvas void overlap(const Canvas& can, size_t r, size_t c);
};
ostream& operator<< (ostream& sout, const Canvas& f);
= default;
// the only data member
// validates row r and column c
   COMP 5421/1-BB, Assignment 4, Summer 2021, page 14 of 21

8.1 FYI
To make the assignment workload lighter, the following features were dropped from the original version of Canvas. They are listed here so that you might want to implement them some time after the exam to enhance your Canvas class.
􏰀 Allow the user to index both rows and column from 1
􏰀 Overload the function call operator as a function of two size t arguments to write on a
canvas, similar to put. For example:
  char ch {’*’}; can(1, 2) = ch;
// similar to can.put(1, 2, ch);
ch = can(1, 2);
// similar to
ch = can.get(1,2)
   To serve both const and non-const objects of Canvas, provide two version of the operator. 􏰀 Overload the subscript operator to to support this code segment:
   char ch {’*’}; can[1][2] = ch;
// similar to can.put(1, 2, ch);
ch = can[1][2];
// similar to
ch = can.get(1,2)
  To serve both const and non-const objects of Canvas, provide two version of the operator. 􏰀 Overload the binary operator+ to join two Canvas objects horizontally. The returning
Canvas object will be large enough to accommodate both Canvas objects.
