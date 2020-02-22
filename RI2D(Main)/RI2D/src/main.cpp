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
// GyroH                gyro          H               
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
  Arm.stop(hold);

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


void drive(int deg, int speed)
{
  LeftBack.setVelocity(speed, percent);
  RightBack.setVelocity(speed, percent);
  LeftFront.setVelocity(speed, percent);
  RightFront.setVelocity(speed, percent);

  LeftBack.spinFor(deg, degrees, false);
  RightBack.spinFor(deg, degrees, false);
  LeftFront.spinFor(deg, degrees, false);
  RightFront.spinFor(deg, degrees, false);
}

void trayOut(int deg, int speed)
{
  AngleAdjuster.setVelocity(speed, percent);
  AngleAdjuster.spinToPosition(deg, degrees, false);
}


void intakeH(int speed)
{
  LeftIntake.spin(forward, speed, percent);
  RightIntake.spin(forward, speed, percent); 
}

void outtake(int speed)
{
  LeftIntake.spin(reverse, speed, percent);
  RightIntake.spin(reverse, speed, percent);
}

void armH(int deg, int speed)
{
  Arm.setVelocity(speed, percent);
  Arm.spinFor(deg, degrees, false);
}

void driveRight(int deg, int speed)
{
  RightBack.setVelocity(speed, percent);
  RightFront.setVelocity(speed, percent);
  RightBack.spinFor(deg, degrees, false);
  RightFront.spinFor(deg, degrees, false);
}

void driveLeft(int deg, int speed)
{
  LeftBack.setVelocity(speed, percent);
  LeftFront.setVelocity(speed, percent);
  LeftFront.spinFor(deg, degrees, false);
  LeftBack.spinFor(deg, degrees, false);
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  /*
  drive(360 * 2, 50);
  wait(2, sec);
  drive(-360 * 2, 100);
  wait(1, sec);
  outtake(100);
  wait(1, sec);
  armH(360, 100);
  wait(1, sec);
  outtake(0);
  armH(-360, 100);*/
  drive(250, 50);
  wait(0.5, sec);
  drive(-100, 50);
  outtake(100);
  wait(1, sec);
  outtake(0);
  wait(1, sec);
  intakeH(100);
  drive(540 + 140, 30);
  wait(1, sec);
  driveRight(-230, 30);
  driveLeft(230, 30);
  wait(1, sec);
  drive(360 * 2 - 50, 60);
  wait(1, sec);
  driveLeft(200, 30);
  driveRight(-200, 30);
  wait(0.5, sec);
  drive(180+ 80, 20);
  intakeH(0);
  wait(1, sec);
  outtake(30);
  wait(1.5, sec);
  outtake(0);
  AngleAdjuster.spinFor(360 * 2, degrees, false);
  wait(3, sec);
  drive(-360, 100);
  AngleAdjuster.spinFor(-360 * 2, degrees, false);
   // ..........................................................................

  // drive (int degrees, int speed) degrees spin, speed is in percent
  // driveRight (int degrees, int speed) drives only the right wheels
  // driveLeft (int degrees, int speed) drives only the left wheels
  // armH (int degrees, int speed) controls speed of arm
  // intake (int speed) controls speed of intake
  // outtake (int speed) contorls speed of outake
  // trayIn (int degrees, int speed) degrees of rotation
  // trayOut (int degrees, int speed) degrees of rotation
  // wait(double number here, sec)
  
  

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

  // CHANGE THIS ONE
  double sensitivity = 0.65;
  while (1) 
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values 
    // update your motors, etc.
    // ........................................................................
    /*
      _____       _           
     |  __ \     (_)          
     | |  | |_ __ ___   _____ 
     | |  | | '__| \ \ / / _ \
     | |__| | |  | |\ V /  __/
     |_____/|_|  |_| \_/ \___|
    */
    
    Controller1.ButtonUp.pressed(armMacro); 
    
    rightDrive = (int)(Controller1.Axis2.position(percent) - Controller1.Axis1.position(percent) * (sensitivity)); // (Front//Back) - (Left//Right)
    leftDrive = (int)(Controller1.Axis2.position(percent) + Controller1.Axis1.position(percent) * (sensitivity));  // (Front//Back) + (Left//Right)

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
    if (Controller1.ButtonL1.pressing())      angleAdjusterSpeed = 35;
    else if (Controller1.ButtonL2.pressing()) angleAdjusterSpeed = -100;
    AngleAdjuster.spin(forward, angleAdjusterSpeed, percent);

    armSpeed = 0;
    angleAdjusterSpeed = 0;
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