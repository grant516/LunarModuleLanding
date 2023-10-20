#include "LunarModule.h"

int LunarModule::groundCollision(Ground ground) 
{
   //bool isCollide = false;
   if (ground.getElevation(point) <= 0) 
   {
      if (ground.hitGround(point, width)) 
      {
         //isCollide = true;
         safe_landing = 1;
      }
   }
   else if (ground.onPlatform(point, width)) 
   {
      if (totalVelocity >= MAX_LANDING_SPEED) 
      {
         //isCollide = true;
         safe_landing = 1;
      }
      else 
      {
         //isCollide = false;
         safe_landing = 2;
      }
   }

   //return isCollide;
   return safe_landing;
}

void LunarModule::updatePhysics() 
{

   aRadians = physics.radians(aDegrees);

   if (thrusters && fuel > 0)
   {
      accelerationThrust = physics.computeAcceleration(THRUST, WEIGHT);
      ddxThrust = physics.computeHoriztalComponent(aRadians, accelerationThrust);
      ddyThrust = physics.computeVerticalComponent(aRadians, accelerationThrust);
   }
   else
   {
      ddxThrust = physics.computeVerticalComponent(aRadians, 0);
      ddyThrust = physics.computeVerticalComponent(aRadians, 0);
   }
   
   ddx = -ddxThrust;
   ddy = GRAVITY + ddyThrust;

   dx = physics.computeVelocity(dx, ddx, t);
   dy = physics.computeVelocity(dy, ddy, t);
   x = physics.computeDistance(x, dx, ddx, t);
   y = physics.computeDistance(y, dy, ddy, t);

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