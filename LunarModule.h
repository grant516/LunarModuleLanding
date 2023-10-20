#pragma once
#include "point.h"
#include "ground.h"
#include "physics.h"

class LunarModule
{
private:

   Physics physics;
   Point point;
   double WEIGHT = 15103.000;   // Weight in KG
   double THRUST = 45000.000;   // Thrust of main engine, in Newtons (kg m/s^2)
   double MAX_LANDING_SPEED = 4.0;
   double dy = physics.getGravity();
   double dx = 0;
   double y;
   double x;
   double drawAngle;
   double aDegrees;
   double time = 0.1;
   double totalVelocity;
   double weight = 15103.000;
   int fuel = 5000;
   int width = 20;
   int safe_landing = 0;
   bool thrusters;

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

