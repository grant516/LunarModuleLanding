#include "LunarModule.h"

int LunarModule::groundCollision(Ground ground) 
{
   if (ground.onPlatform(point, width))
   {
      if (totalVelocity >= MAX_LANDING_SPEED)
      {
         safe_landing = 1;
      }
      else
      {
         safe_landing = 2;
      }
   }
   else if (ground.getElevation(point) <= 0) 
   {   
      if (ground.hitGround(point, width))
      {
         safe_landing = 1;
      }
      else
         safe_landing = 0;
   }

   return safe_landing;
}

void LunarModule::updatePhysics() 
{
   double aRadians = physics.radians(aDegrees);
   double ddxThrust;
   double ddyThrust;
   double ddx;
   double ddy;

   if (thrusters && fuel > 0)
   {
      double accelerationThrust = physics.computeAcceleration(THRUST, WEIGHT);
      ddxThrust = physics.computeHoriztalComponent(aRadians, 
         accelerationThrust);
      ddyThrust = physics.computeVerticalComponent(aRadians, 
         accelerationThrust);
   }
   else
   {
      ddxThrust = physics.computeVerticalComponent(aRadians, 0);
      ddyThrust = physics.computeVerticalComponent(aRadians, 0);
   }
   
   ddx = -ddxThrust;
   ddy = GRAVITY + ddyThrust;

   dx = physics.computeVelocity(dx, ddx, time);
   dy = physics.computeVelocity(dy, ddy, time);
   x = physics.computeDistance(x, dx, ddx, time);
   y = physics.computeDistance(y, dy, ddy, time);

   totalVelocity = physics.computeTotalComponent(dx, dy);

   setPoint(x, y);
}

void LunarModule::updateFuel(bool isTurning, bool isThrustersOn) 
{

   if (fuel > 0) 
   {
      if (isTurning) 
      {
         fuel -= 1;
      }
      if (isThrustersOn) 
      {
         fuel -= 10;
      }
   }
}