/**
 *  @author Stephen Gilbert
 *  @version CS 150 Testing Program
 *  @file main.cpp
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

#include "cs150check.h"

#include "h13.h"

/**
 * Run your program's tests
 */
void runTests()
{
	///////////// Begin a set of tests
	beginTests(); // test heading

    /////// Tests for //////////////////////
	beginFunctionTest("Point Structure"); // function name

#ifdef POINT_DONE
	// Test the get() function
	istringstream sin("5,10 7,15");
	Point p1, p2;
	get(sin, p1);
	get(sin, p2);
	assertEqualsMsg("Read x value into point p1.", 5, p1.x);
	assertEqualsMsg("Read y value into point p1.", 10, p1.y);
    assertEqualsMsg("Read x value into point p2.", 7, p2.x);
    assertEqualsMsg("Read y value into point p2.", 15, p2.y);

	// Test the print() function
	ostringstream sout;
	print(sout, p1);
	assertEqualsMsg("Print correctly displays p1", "(5, 10)", sout.str());
	sout.str(""); // clear
	print(sout, p2);
    assertEqualsMsg("Print correctly displays p2", "(7, 15)", sout.str());

	// Test the distance method
    assertDoubleEqualsMsg("Check distance between p1 and p2", sqrt(29), distanceBetween(p1, p2), 1E-10);

    // Test the midpoint method
    Point mid = midpoint(p1, p2);
    assertEqualsMsg("Check mid.x in midpoint between p1 and p2", 6, mid.x);
    assertEqualsMsg("Check mid.y in midpoint between p1 and p2", 12, mid.y);

#else
    cerr << "Define the Point structure. Then, uncomment #define POINT_DONE in h12.h" << endl;
#endif

	endFunctionTest(); // end

    beginFunctionTest("Triangle Structure"); // function name

#ifdef TRIANGLE_DONE

    {
        // Define three points
        Point p1 = {1, 3}, p2 = {-2, -2}, p3 = {3, -1};

        // Create a Triangle variable
        Triangle t = {p1, p2, p3};

        // Now, test the perimeter() function
        assertDoubleEqualsMsg("Check perimeter of Triangle", 15.4021,  perimeter(t), 1E-5);
    }
    {
        // Define three points
        Point p1 = {2, 3}, p2 = {5, 1}, p3 = {5, 5};

        // Create a Triangle variable
        Triangle t = {p1, p2, p3};

        // Now, test the perimeter() function
        assertDoubleEqualsMsg("Check perimeter of Triangle", 11.2111,  perimeter(t), 1E-5);
    }
    {
        // Define three points
        Point p1 = {4, 4}, p2 = {3, 5}, p3 = {1, 1};

        // Create a Triangle variable
        Triangle t = {p1, p2, p3};

        // Now, test the perimeter() function
        assertDoubleEqualsMsg("Check perimeter of Triangle", 10.129,  perimeter(t), 1E-5);
    }
    {
        // Define three points
        Point p1 = {2, 3}, p2 = {2, 2}, p3 = {1, 3};

        // Create a Triangle variable
        Triangle t = {p1, p2, p3};

        // Now, test the perimeter() function
        assertDoubleEqualsMsg("Check perimeter of Triangle", 3.41421,  perimeter(t), 1E-5);
    }
    {
        // Define three points
        Point p1 = {3, 2}, p2 = {2, 5}, p3 = {3, 4};

        // Create a Triangle variable
        Triangle t = {p1, p2, p3};

        // Now, test the perimeter() function
        assertDoubleEqualsMsg("Check perimeter of Triangle", 6.57649,  perimeter(t), 1E-5);
    }
    {
        // Define three points
        Point p1 = {3, 3}, p2 = {2, 2}, p3 = {4, 1};

        // Create a Triangle variable
        Triangle t = {p1, p2, p3};

        // Now, test the perimeter() function
        assertDoubleEqualsMsg("Check perimeter of Triangle", 5.88635,  perimeter(t), 1E-5);
    }

#else
    cerr << "Define the Triangle structure. Then, uncomment #define TRIANGLE_DONE in h12.h" << endl;
#endif

    endFunctionTest(); // end


   ///////// End all test runs /////////////////////////
    endTests();

}


