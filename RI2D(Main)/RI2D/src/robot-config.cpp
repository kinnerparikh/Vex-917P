#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor RightFront = motor(PORT12, ratio18_1, true);
motor RightBack = motor(PORT20, ratio18_1, true);
motor LeftFront = motor(PORT15, ratio18_1, false);
motor LeftBack = motor(PORT19, ratio18_1, false);
motor Arm = motor(PORT13, ratio36_1, true);
motor RightIntake = motor(PORT14, ratio18_1, true);
motor LeftIntake = motor(PORT11, ratio18_1, false);
motor AngleAdjuster = motor(PORT18, ratio36_1, true);
gyro GyroH = gyro(Brain.ThreeWirePort.H);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}