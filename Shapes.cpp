//: Shapes.cpp

/*
Title: Shapes.cpp
Description: Program that creates shapes given various inputs. The program uses many classes such as point, shape, circle, square, and triangle that inherit from one another.
Date: February 16, 2021
Author: Pawan Iyer
Version: 1.0
Copyright: 2021 Pawan Iyer
*/

/*
Program Purpose:
Write a program that creates a class hierarchy for simple geometry.
a. Start with a Point class to hold x and y values of a point. Overload
the >> operator to print point values and the + and – operators
to add and subtract point coordinates (hint: keep x and y separate
In the calculation).
b. Create a base class Shape which will form the basis of your shapes.
The Shape class will contain functions to calculate area and
circumference of the shape, plus provide the coordinates (Points) of
a rectangle that encloses the shape (a bounding box). These will be
overloaded by the derived classes as necessary. Create a display()
function that will display the name of the class plus all stored
information about the class (including area, circumference, and
bounding box).
2 Computer Science 206 / Assignment 3
c. Build the hierarchy by creating the Shape classes Circle, Square,
and Triangle. For these derived classes, create default
constructors and constructors whose arguments can initialize the
shapes appropriately using the correct number of Point objects
(i.e., Circle requires a Point center and a radius; Square requires
four Point vertices, while Triangle requires three Point vertices).
d. In main(), create one instance each of the following: a Circle with a
radius of 23, a Square with sides 25, and a Triangle with sides 10,
20, 30. Define all of them so that the origin (0,0) is somewhere
within each object. Display the information from each object.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
private:
    double y;   //Variables
    double x;
    
public:
    Point() //Default Constructor
    {
        y = 0;
        x = 0;
    }

    friend ostream& operator << (ostream& stream, Point &pointer)   //Start Reading
    {
        stream << "[" << pointer.x << "," << pointer.y << "]";
        return stream;
    }

    Point(double dx, double dy) //Constructor
    {
        x = dx;
        y = dy;
    }

  double get_x()const   //Get X
    {
        return x;
    }

    Point operator+ (Point& pointing)   //+ Operaator
    {
        Point *pointer;
        pointer -> setPoint(x + pointing.get_x(), y + pointing.get_y());
        return *pointer;
    }

    void setPoint(double dx, double dy) //Set point
    {
        y = dy;
        x = dx; 
    }

    Point operator- (Point& pointing)   //- Operator
    {
        Point *pointer;
        pointer -> setPoint(x - pointing.get_x(), y - pointing.get_y());
        return *pointer;
    }

    double get_y()const //Get Y
    {
        return y;
    }
};

class Shape
{
public:
    Shape() //Default Constructor
    {
        height = 0;
        width = 0;
    }

    Shape(double w, double h)   //Constructor
    {
        height = h;
        width = w;
    }

    virtual void display() = 0;
    virtual double area() = 0;
    virtual double circumference() = 0;
    
protected:
    Point center;   //Variables
    double width;
    double height;
};

class Circle : public Shape
{
    double radius;  //Variables
    Point center;
public:
    Circle(Point p, double r)   //Constructor
    {
        center = p; 
        radius = r;
    }

    Circle()    //Default Constructor
    {

    }

    double getRadius()  //Get radius
    {
        return radius;
    }

    void setRadius(double r)    //Set radius
    {
        radius = r;
    }

    double area()   //Area function
    {
        return radius * radius * 3.14159;
    }

    double circumference()  //Circumference function
    {
        return 2 * 3.14159 * radius;
    }

    void display()  //Display function
    {
        std::cout << "Circle: " << std::endl;
        std::cout << "Center: " << center << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Circumference: " << circumference() << std::endl;
    }
};

class Triangle : public Shape
{
    Point p_1;  //Variables
    int one_side;
    Point p_2;
    int two_side;
    Point p_3;
    int three_side;
  
public:
    Triangle(Point point_1, Point point_2, Point point_3, int side_1, int side_2, int side_3)   //Constructor
    {
        one_side = side_1;
        p_1 = point_1;
        two_side = side_2;
        p_2 = point_2;
        three_side = side_3;
        p_3 = point_3;
    }

    Triangle()  //Default Constructor
    {

    }
    
    double circumference()  //Perimeter function
    {
        return one_side + two_side + three_side;
    }

    double area()   //Area function
    {
        double x = circumference() / 2;
        double area = sqrt((x - one_side) * (x - two_side) * (x - three_side) * x);
        return area;
    }

    void display()  //Display function
    {
        std::cout << "Triangle: " << "\n" << "The Three Points: " << p_1 << " " << p_2 << " " << p_3 << std::endl;
        std::cout << "Side Length 1: " << one_side << std::endl;
        std::cout << "Side Length 2: " << two_side << std::endl;
        std::cout << "Side Length 3: " << three_side << std::endl;
        std::cout << "Perimeter: " << circumference() << std::endl;
        std::cout << "Area: " << area() << std::endl;    
    }
};

class Square: public Shape
{
    double side_length; //Variables
    Point p_1;
    Point p_2;
    Point p_3;
    Point p_4;

public:
    Square(Point p_1, Point p_2, Point p_3, Point p_4, double s)    //Constructor
    {
        side_length = s;
        this->p_1 = p_1;
        this->p_2 = p_2;
        this->p_3 = p_3;
        this->p_4 = p_4;
    }

    Square()    //Default Constructor
    {

    }

    void setSide(double s)  //Set side length
    {
        side_length = s;
    } 

    double getSide()    //Get side length
    {
        return side_length;
    }
    
    double circumference()  //Perimeter function
    {
        return 4*side_length;
    }

    double area() //Area function
    {
        return side_length*side_length;
    }

    void display()  //Display function
    {
        std::cout << "Square: " << "\n" << "The Four Points: " << p_1 << " " << p_2 << " " << p_3 << " " << p_4 << std::endl;
        std::cout << "Side Length: " << side_length << std::endl; 
        std::cout << "Area: " << area() << std::endl;
        std::cout << "Perimeter: " << circumference() << std::endl;
    }
};

int main(); //Initializer

int main()
{
    Point ci1(0,0);  //Points

    Point sq1(0,0);
    Point sq2(25,0);
    Point sq3(0,-25);
    Point sq4(25,-25);

    Point tri1(0,0);
    Point tri2(3,4);
    Point tri3(-4,6);

    Circle circle(ci1,23);   //Circle
    Triangle triangle(tri1,tri2,tri3,10,20,30);   //Triangle
    Square square(sq1,sq2,sq3,sq4,25);  //Square

    circle.display();
    std::cout << std::endl;
    square.display();
    std::cout << std::endl;
    triangle.display();

    return 0;
}

