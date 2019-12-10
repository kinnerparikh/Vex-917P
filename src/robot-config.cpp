#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftDR4BMotor = motor(PORT1, ratio36_1, true);
motor LeftDriveMotor = motor(PORT2, ratio18_1, true);
motor LeftIntakeMotor = motor(PORT3, ratio18_1, false);
motor CubeTrayMotor = motor(PORT4, ratio36_1, true);
motor RightIntakeMotor = motor(PORT5, ratio18_1, true);
motor CenterDriveMotor = motor(PORT6, ratio18_1, false);
motor RightDriveMotor = motor(PORT10, ratio18_1, false);
motor RightDR4BMotor = motor(PORT21, ratio36_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}