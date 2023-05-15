#include "Point.hpp"

using namespace ariel;

/**
 * Constructor for point
 * @param x X coordinate
 * @param y Y coordinate
 */
Point::Point(double x_c, double y_c) {}

/**
 *  Calculation of distance between 2 points
 * @param p destination points
 * @return the distance
 */
double Point::distance(Point point) const {return 0;}

/**
 * Print the values of the point
 * @return A string that contains the values
 */
std::string Point::print() {return NULL;}

/**
 * The function calculates the closest point that can be reached to the target point using the obtained distance
 * @param src source points
 * @param des destination points
 * @param distance the distance that can be move
 * @return the point where you can go
 */
Point Point::moveTowards(Point src, Point des, double distance) const {return NULL;}

/**
 * Setter for x coordinate
 * @param x x coordinate
 */
void Point::setx(double x_c) {}

/**
 * Setter for x coordinate
 * @param y y coordinate
 */
void Point::sety(double y_c) {}

/**
 * getter for x coordinate
 * @return x coordinate
 */
double Point::getx() const {return 0;}

/**
 *  getter for y coordinate
 * @return y coordinate
 */
double Point::gety() const {return 0;}