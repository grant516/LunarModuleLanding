#pragma once
#include <cmath>
#include <iostream>
using namespace std;

class Physics
{
private:
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2

public:
    /***************************************************
     * COMPUTE DISTANCE
     * Apply inertia to compute a new position using the distance equation.
     * The equation is:
     *     s = s + v t + 1/2 a t^2
     * INPUT
     *     s : original position, in meters
     *     v : velocity, in meters/second
     *     a : acceleration, in meters/second^2
     *     t : time, in seconds
     * OUTPUT
     *     s : new position, in meters
     **************************************************/
   double computeDistance(double s, double v, double a, double t);

    /**************************************************
     * COMPUTE ACCELERATION
     * Find the acceleration given a thrust and mass.
     * This will be done using Newton's second law of motion:
     *     f = m * a
     * INPUT
     *     f : force, in Newtons (kg * m / s^2)
     *     m : mass, in kilograms
     * OUTPUT
     *     a : acceleration, in meters/second^2
     ***************************************************/
    double computeAcceleration(double f, double m);

    /***********************************************
     * COMPUTE VELOCITY
     * Starting with a given velocity, find the new
     * velocity once acceleration is applied. This is
     * called the Kinematics equation. The
     * equation is:
     *     v = v + a t
     * INPUT
     *     v : velocity, in meters/second
     *     a : acceleration, in meters/second^2
     *     t : time, in seconds
     * OUTPUT
     *     v : new velocity, in meters/second
     ***********************************************/
    double computeVelocity(double v, double a, double t);


    /***********************************************
     * COMPUTE VERTICAL COMPONENT
     * Find the vertical component of a velocity or acceleration.
     * The equation is:
     *     cos(a) = y / total
     * This can be expressed graphically:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    |a/
     *    |/
     * INPUT
     *     a : angle, in radians
     *     total : total velocity or acceleration
     * OUTPUT
     *     y : the vertical component of the total
     ***********************************************/
    double computeVerticalComponent(double a, double total);

    /***********************************************
     * COMPUTE HORIZONTAL COMPONENT
     * Find the horizontal component of a velocity or acceleration.
     * The equation is:
     *     sin(a) = x / total
     * This can be expressed graphically:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    |a/
     *    |/
     * INPUT
     *     a : angle, in radians
     *     total : total velocity or acceleration
     * OUTPUT
     *     x : the vertical component of the total
     ***********************************************/
    double computeHoriztalComponent(double a, double total);

    /************************************************
     * COMPUTE TOTAL COMPONENT
     * Given the horizontal and vertical components of
     * something (velocity or acceleration), determine
     * the total component. To do this, use the Pythagorean Theorem:
     *    x^2 + y^2 = t^2
     * where:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    | /
     *    |/
     * INPUT
     *    x : horizontal component
     *    y : vertical component
     * OUTPUT
     *    total : total component
     ***********************************************/
    double computeTotalComponent(double x, double y);


    /*************************************************
     * RADIANS FROM DEGEES
     * Convert degrees to radians:
     *     radians / 2pi = degrees / 360
     * INPUT
     *     d : degrees from 0 to 360
     * OUTPUT
     *     r : radians from 0 to 2pi
     **************************************************/
    double radians(double d);

    double getGravity() {
        return GRAVITY;
    }

};

