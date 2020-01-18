/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightFront           motor         12              
// RightBack            motor         20              
// LeftFront            motor         15              
// LeftBack             motor         19              
// Arm                  motor         13              
// RightIntake          motor         14              
// LeftIntake           motor         16              
// AngleAdjuster        motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "math.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void driveSpeed(int speed)
{
  LeftBack.setVelocity(speed, percent);
  RightBack.setVelocity(speed, percent);
  LeftFront.setVelocity(speed, percent);
  RightFront.setVelocity(speed, percent);
}

void drive(int deg, bool wait)
{
  LeftBack.spinFor(deg, degrees, false);
  RightBack.spinFor(deg, degrees, false);
  LeftFront.spinFor(deg, degrees, false);
  RightFront.spinFor(deg, degrees, wait);
}

void tray(int deg, int speed)
{
  AngleAdjuster.setVelocity(speed, percent);
  AngleAdjuster.spinFor(deg, degrees, true);
}


void intake(int speed)
{
  LeftIntake.spin(forward, speed, percent);
  RightIntake.spin(forward, speed, percent);
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  driveSpeed(70);
  drive(-360 * 2, true);
  wait(2, sec);
  drive(360 * 2, true);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

int abs(int num)
{
  if (num < 0)
  {
    return num * -1;
  }
  return num;
}

void armMacro()
{
  AngleAdjuster.setPosition(300, degrees);
}

void usercontrol(void) 
{

  // User control code here, inside the loop
  int rightDrive;
  int leftDrive;
  int intakeSpeed;

  int armSpeed = 0;
  int angleAdjusterSpeed = 0; 


  // CHANGE THIS
  double sensitivity = 0.75;
  while (1) 
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values 
    // update your motors, etc.
    // ........................................................................
    AngleAdjuster.stop(hold);
    /*
      _____       _           
     |  __ \     (_)          
     | |  | |_ __ ___   _____ 
     | |  | | '__| \ \ / / _ \
     | |__| | |  | |\ V /  __/
     |_____/|_|  |_| \_/ \___|
    */
    
    rightDrive = (int)((Controller1.Axis2.position(percent) - Controller1.Axis1.position(percent)) * sensitivity); // (Front//Back) - (Left//Right)
    leftDrive = (int)(Controller1.Axis2.position(percent) + Controller1.Axis1.position(percent) * sensitivity);  // (Front//Back) + (Left//Right)

    RightBack.spin(forward, rightDrive, percent);
    RightFront.spin(forward, rightDrive, percent);
    LeftBack.spin(forward, leftDrive, percent);
    LeftFront.spin(forward, leftDrive, percent);

    /*
      _____       _        _        
     |_   _|     | |      | |       
       | |  _ __ | |_ __ _| | _____ 
       | | | '_ \| __/ _` | |/ / _ \
      _| |_| | | | || (_| |   <  __/
     |_____|_| |_|\__\__,_|_|\_\___|
    */
    intakeSpeed = Controller1.Axis3.position(percent); // (Front//Back)
    RightIntake.spin(forward, intakeSpeed, percent);
    LeftIntake.spin(forward, intakeSpeed, percent);

    /*                    
         /\                   
        /  \   _ __ _ __ ___  
       / /\ \ | '__| '_ ` _ \ 
      / ____ \| |  | | | | | |
     /_/    \_\_|  |_| |_| |_|
    */
    
    if (Controller1.ButtonR1.pressing()){      armSpeed = 50; armMacro();}  // Set speed to 50 if pressing R1
    else if (Controller1.ButtonR2.pressing()) armSpeed = -50; // Set speed to -50 if pressing R2
    else if (Arm.position(degrees) >= 135) Arm.stop(hold);
    Arm.spin(forward, armSpeed, percent);

    /*
                           _                    _ _           _            
         /\               | |          /\      | (_)         | |           
        /  \   _ __   __ _| | ___     /  \   __| |_ _   _ ___| |_ ___ _ __ 
       / /\ \ | '_ \ / _` | |/ _ \   / /\ \ / _` | | | | / __| __/ _ \ '__|
      / ____ \| | | | (_| | |  __/  / ____ \ (_| | | |_| \__ \ ||  __/ |   
     /_/    \_\_| |_|\__, |_|\___| /_/    \_\__,_| |\__,_|___/\__\___|_|   
                      __/ |                     _/ |                       
                     |___/                     |__/ 
    */
    if (Controller1.ButtonL1.pressing())      angleAdjusterSpeed = 50;
    else if (Controller1.ButtonL2.pressing()) angleAdjusterSpeed = -50;
    AngleAdjuster.spin(forward, angleAdjusterSpeed, percent);
    Brain.Screen.clearLine();
    Brain.Screen.print(AngleAdjuster.position(degrees));

    armSpeed = 0;
    angleAdjusterSpeed = 0;

    if (Controller1.ButtonA.pressing())
    {
      RightBack.  spinFor(-360, degrees, false);
      LeftBack.   spinFor(-360, degrees, false);
      RightFront. spinFor(-360, degrees, false);
      LeftFront.  spinFor(-360, degrees, false);
      RightIntake.spinFor(-360, degrees, false);
      LeftIntake. spinFor(-360, degrees, true);
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
