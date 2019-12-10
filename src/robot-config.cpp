#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveMotor = motor(PORT1, ratio18_1, true);
motor RightDriveMotor = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);
motor CenterDriveMotor = motor(PORT5, ratio18_1, false);
motor LeftDR4BMotor = motor(PORT7, ratio36_1, true);
motor RightDR4BMotor = motor(PORT8, ratio36_1, false);
motor LeftIntakeMotor = motor(PORT2, ratio18_1, false);
motor RightIntakeMotor = motor(PORT6, ratio18_1, true);
motor CubeTrayMotor = motor(PORT4, ratio36_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}