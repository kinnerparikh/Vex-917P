using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftDriveMotor;
extern motor RightDriveMotor;
extern controller Controller1;
extern motor CenterDriveMotor;
extern motor LeftDR4BMotor;
extern motor RightDR4BMotor;
extern motor LeftIntakeMotor;
extern motor RightIntakeMotor;
extern motor CubeTrayMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );