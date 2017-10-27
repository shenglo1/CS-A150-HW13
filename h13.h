/**
    @file h13.h
    @author YOUR NAME HERE
    @date what day and meeting time
    Declarations for CS 150 Homework
*/
#ifndef H13_H_
#define H13_H_
#include "cs150check.h"

#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>

#define POINT_DONE
// Place your Point structure here and UNCOMMENT the line above

struct Point
{
    int x;
    int y;
};

#ifdef POINT_DONE

/**
 * Reads a point in the form x,y.
 * @param in the input stream.
 * @param p the Point to populate
 */
void get(std::istream& in, Point& p);

/**
 * Displays a Point in the form (x, y).
 * @param out the stream to print on
 * @param p the Point to print
 */
void print(std::ostream& out, const Point& p);

/**
 * Calculate the distance between two Points.
 * @param a the first point.
 * @param b the second point.
 * @return the distance as a double.
 */
double distanceBetween(const Point& a, const Point& b);

/**
 * Given two points, find their midpoint.
 * @param a the first point.
 * @param b the second point.
 * @return the midpoint.
 */
Point midpoint(const Point& a, const Point& b);

#define TRIANGLE_DONE
// Uncomment the line above, when you have defined your Triangle
// Place your Triangle structure here

struct Triangle
{
    Point p1;
    Point p2;
    Point p3;
};






#ifdef TRIANGLE_DONE

/**
 * Calculates the perimeter of the Triangle t.
 * @param t the Triangle to examine.
 * @return the perimeter.
 */
double perimeter(const Triangle& t);


#endif
#endif
#endif
