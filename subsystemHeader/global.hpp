#include "main.h"
using namespace pros;

extern pros::Motor krutilka;
extern pros::Motor liftLeft;
extern pros::Motor liftRight;
extern pros::Motor backLeft;
extern pros::Motor frontLeft;
extern pros::Motor backRight;
extern pros::Motor frontRight;
extern pros::Motor intake;
extern pros::Motor backlift;


extern pros::Controller controller;

extern std::shared_ptr<ChassisController> chassis;

extern std::shared_ptr<ChassisController> chassisTurn;

extern std::shared_ptr<AsyncPositionController<double, double>> intakeController;

extern std::shared_ptr<AsyncPositionController<double, double>> liftController;

extern std::shared_ptr<AsyncPositionController<double, double>> backliftController;

extern pros::ADIGyro gyro;

extern pros::Vision vision;
