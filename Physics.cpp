#include "Physics.h"

double Physics::computeDistance(double s, double v, double a, double t) {
   double distance;
   distance = s + v * t + .5 * a * pow(t, 2);
   return (distance);
}

double Physics::computeAcceleration(double f, double m) {
   double acceleration = f / m;
   return acceleration;
}

double Physics::computeVelocity(double v, double a, double t) {
   double velocity = v + a * t;
   return velocity;
}

double Physics::computeVerticalComponent(double a, double total) {
   double y;
   y = cos(a) * total;
   return y;
}

double Physics::computeHoriztalComponent(double a, double total) {
   double x;
   x = sin(a) * total;
   return x;
}

double Physics::computeTotalComponent(double x, double y) {
   double t;
   t = sqrt(pow(x, 2) + pow(y, 2));
   return t;
}

double Physics::radians(double d) {
   double pi = 2 * acos(0.0);
   double r;
   r = (d * pi) / 180.0;
   return r;
}