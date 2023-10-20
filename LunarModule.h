#pragma once
#include "point.h"
#include "ground.h"
#include "physics.h"

class LunarModule
{
private:

   Physics physics;
   double dx = 0;
   double dy = physics.getGravity();
   double y;
   double x;
   double drawAngle;
   double aDegrees;
   double t = 0.1;
   double aRadians;            // Angle in radians
   double accelerationThrust = 0;  // Acceleration due to thrust 
   double ddxThrust = 0;           // Horizontal acceleration due to thrust
   double ddyThrust = 0;           // Vertical acceleration due to thrust
   double ddx = 0;                 // Total horizontal acceleration
   double ddy;                 // Total vertical acceleration
   bool thrusters;
   Point location;
   double weight = 15103.000;
   double width = 20;
   double totalVelocity;
   double acceleration;
   int fuel = 5000;
   Point point;
   double MAX_LANDING_SPEED = 4.0;
   int safe_landing = 0;

public:

   int groundCollision(Ground ground);

   void updatePhysics();

    void updateAngle(double angle) {
        drawAngle = angle;
    }

    void updateDegrees(double d) {
       aDegrees = d;
    }

    double getAngle()
    {
       return drawAngle;
    }

    double getDegrees()
    {
       return aDegrees;
    }

    void updateFuel(bool isTurning, bool isThrustersOn);

    Point getPoint() {
       return point;
    }

    int getFuel() {
       return fuel;
    }

    double getTotalVelocity() {
       return totalVelocity;
    }

    void setThrusters(bool t)
    {
       thrusters = t;
    }

    double getX() {
       return x;
    }

    double getY() {
       return y;
    }

    void setPoint(double _x, double _y) {
       x = _x;
       y = _y;
       point.setX(_x);
       point.setY(_y);
    }

};

