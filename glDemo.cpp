/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "LunarModule.h"
#include <list>
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(const Point& ptUpperRight) :
        angle(0.0),
        ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
        ground(ptUpperRight)
   { 
      for (int i = 0; i < 50; i++)
          starsList.push_back(Point(random(0, 400), random(0, 400)));

      do 
      {
         LM.setPoint(random(0, 400), random(200, 400));
      } while (LM.groundCollision(ground));
   }

   // this is just for test purposes.  Don't make member variables public!
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   //unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar;
   list<Point> starsList;
   LunarModule LM; // The LM object on the screen
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo * pDemo = (Demo *)p;  

   int onTheGround = pDemo->LM.groundCollision(pDemo->ground);
   if (onTheGround != 0)
   {
      string msg = "";
      if (onTheGround == 2)
         msg = "Safe Landing!";
      else
         msg = "You Crashed!";

      for (Point star : pDemo->starsList) {
         gout.drawStar(star, random(0, 255));
      }

      // draw the ground
      pDemo->ground.draw(gout);

      // draw the lander and its flames
      gout.drawLander(pDemo->LM.getPoint() /*position*/, 
         pDemo->LM.getAngle() /*angle*/);
      gout.drawLanderFlames(pDemo->LM.getPoint(), 
         pDemo->LM.getAngle(), /*angle*/
         pUI->isDown(), pUI->isLeft(), pUI->isRight());

      // put some text on the screen
      gout.setPosition(Point(160, 200));
      gout << msg << endl;

      gout.setPosition(Point(10.0, 380.0));
      gout << "Fuel:\t\t" << pDemo->LM.getFuel() << "\n";
      gout << "Altitude:\t\t" << pDemo->LM.getY() << "\n";
      gout << "Speed:\t\t" << pDemo->LM.getTotalVelocity() 
         << " m/s" << "\n";
   }
   else
   {
      pDemo->LM.updatePhysics();

      // move the ship around
      if (pUI->isRight())
      {
         pDemo->LM.updateAngle(pDemo->LM.getAngle() - 0.1);
         pDemo->LM.updateDegrees(pDemo->LM.getDegrees() - 10);
         pDemo->LM.updateFuel(true, false);
      }

      if (pUI->isLeft())
      {
         pDemo->LM.updateAngle(pDemo->LM.getAngle() + 0.1);
         pDemo->LM.updateDegrees(pDemo->LM.getDegrees() + 10);
         pDemo->LM.updateFuel(true, false);
      }

      if (pUI->isDown())
      {
         pDemo->LM.updateFuel(false, true);
         pDemo->LM.setThrusters(true);
      }
      else
      {
         pDemo->LM.setThrusters(false);
      }

      for (Point star : pDemo->starsList) {
         gout.drawStar(star, random(0, 255));
      }
      
      // draw the ground
      pDemo->ground.draw(gout);
      
      // draw the lander and its flames
      gout.drawLander(pDemo->LM.getPoint() /*position*/, pDemo->LM.getAngle() /*angle*/);
      gout.drawLanderFlames(pDemo->LM.getPoint(), pDemo->LM.getAngle(), /*angle*/
         pUI->isDown(), pUI->isLeft(), pUI->isRight());
      
      // put some text on the screen
      gout.setPosition(Point(10.0, 380.0));
      gout << "Fuel:\t\t" << pDemo->LM.getFuel() << "\n";
      gout << "Altitude:\t\t" << pDemo->LM.getY() << "\n";
      gout << "Speed:\t\t" << pDemo->LM.getTotalVelocity() << " m/s" << "\n";
   }
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance, 
   _In_opt_ HINSTANCE hPrevInstance, 
   _In_ PWSTR pCmdLine, 
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL, 
                "Open GL Demo", 
                 ptUpperRight);

   // Initialize the game class
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);             

   return 0;
}
