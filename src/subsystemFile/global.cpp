#include "main.h"
#include "okapi/api.hpp"
using namespace okapi;
pros::Motor krutilka(21, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor liftLeft(9, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor liftRight(10, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRight(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontLeft(3, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeft(16, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRight(15, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(14, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backlift(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
std::shared_ptr<ChassisController> chassis =
  ChassisControllerBuilder()
    .withMotors({5, 15}, {3, 16})
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{15_in, 12_in}, imev5GreenTPR})
    .withGains(
      {0.0001, 0.001, 0}, // Distance controller gains
      {0.0005, 0.008, 0.00006}, // Turn controller gains
      {0.00001, 0.001, 0.0000001}   // Angle controller gains (helps drive straight)
    )
    /*.withDerivativeFilters(
    std::make_unique<AverageFilter<3>>(), // Distance controller filter
    std::make_unique<AverageFilter<3>>(), // Turn controller filter
    std::make_unique<AverageFilter<3>>()  // Angle controller filter
  )*/
    .build();
    std::shared_ptr<ChassisController> chassisTurn =
      ChassisControllerBuilder()
        .withMotors({5, 15}, {3, 16})
        // Green gearset, 4 in wheel diam, 11.5 in wheel track
        .withDimensions(AbstractMotor::gearset::green, {{15_in, 12_in}, imev5GreenTPR})
        .withGains(
          {0.0001, 0.001, 0}, // Distance controller gains
          {0.0005, 0.008, 0.00006}, // Turn controller gains
          {0.00001, 0.001, 0.0000001}   // Angle controller gains (helps drive straight)
        )
        /*.withDerivativeFilters(
        std::make_unique<AverageFilter<3>>(), // Distance controller filter
        std::make_unique<AverageFilter<3>>(), // Turn controller filter
        std::make_unique<AverageFilter<3>>()  // Angle controller filter
      )*/
        .build();

    std::shared_ptr<AsyncPositionController<double, double>> intakeController =
    AsyncPosControllerBuilder()
    .withMotor(21) // lift motor port 3
    .build();
    std::shared_ptr<AsyncPositionController<double, double>> liftController =
    AsyncPosControllerBuilder()
    .withMotor({9, 10}) // lift motor port 3
    .build();
    std::shared_ptr<AsyncPositionController<double, double>> backliftController =
    AsyncPosControllerBuilder()
    .withMotor(20) // lift motor port 3
    .build();
pros::Controller controller(pros::E_CONTROLLER_MASTER);
