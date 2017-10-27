/**
    @file h13.cpp
    @author your name here
    @date what day and meeting time
*/
#include <string>
#include <cmath>
// Add additional headers here
using namespace std;

string STUDENT = "ilo";     // Add your name Blackboard/occ-email ID

#include "h13.h"
// Add your implementation here


void get(istream& in, Point& p)
{ 
    char ignore;
    in >> p.x >> ignore >> p.y;
}

void print(ostream& out, const Point& p)
{
    out << '(' << p.x << ", " << p.y << ')';
}

double distanceBetween(const Point& a, const Point& b)
{
    int xdiff = a.x - b.x;
    int ydiff = a.y - b.y;
    return sqrt(xdiff * xdiff + ydiff * ydiff);
}

Point midpoint(const Point& a, const Point& b)
{
    int x = (a.x + b.x) / 2;
    int y = (a.y + b.y) / 2;
    Point result = {x, y};
    return result;
}


double perimeter(const Triangle& t)
{

    double x = sqrt((t.p1.x - t.p2.x) * (t.p1.x - t.p2.x) + (t.p1.y - t.p2.y) * (t.p1.y - t.p2.y));
    double y = sqrt((t.p1.x - t.p3.x) * (t.p1.x - t.p3.x) + (t.p1.y - t.p3.y) * (t.p1.y - t.p3.y));
    double z = sqrt((t.p3.x - t.p2.x) * (t.p3.x - t.p2.x) + (t.p3.y - t.p2.y) * (t.p3.y - t.p2.y));
    double result = x + y + z;
    return result;
}
