using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LeftDR4BMotor;
extern motor LeftDriveMotor;
extern motor LeftIntakeMotor;
extern motor CubeTrayMotor;
extern motor RightIntakeMotor;
extern motor CenterDriveMotor;
extern motor RightDriveMotor;
extern motor RightDR4BMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );