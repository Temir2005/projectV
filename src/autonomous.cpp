#include "main.h"


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void redLeftCorner(){
  intakeController->setMaxVelocity(300);
  intakeController->setTarget(320);
  chassis->moveDistance(1_m);
  intakeController->setMaxVelocity(100);
  intakeController->setTarget(-10000);
  chassis->turnAngle(250_deg);
  chassis->setMaxVelocity(200);
  chassis->moveDistance(-2.1_m);
  chassis->turnAngle(-240_deg);
  chassis->setMaxVelocity(150);
  chassis->moveDistance(-8.3_m);
  intakeController->waitUntilSettled();
  intakeController->setMaxVelocity(600);
  intakeController->setTarget(500);
  chassis->setMaxVelocity(600);
  setgoRight(-127);
  pros::delay(1000);
  setgoRight(0);
  //intakeController->waitUntilSettled();
}

void redRightCorner(){
  liftController->setTarget(200);
  liftController->setTarget(-200);
  intakeController->setMaxVelocity(300);
  intakeController->setTarget(320);
  backliftController->setTarget(70);
  chassis->setMaxVelocity(500);
  chassis->turnAngle(-100_deg);
  chassis->moveDistance(0.5_m);
  chassis->setMaxVelocity(400);
  chassis->turnAngle(-200_deg);
  chassis->moveDistanceAsync(0.6_m);
  liftController->setTarget(200);
  liftController->setTarget(-200);
  chassis->waitUntilSettled();
  chassis->turnAngle(-214_deg);
  chassis->setMaxVelocity(400);
  chassis->moveDistance(7_m);
  chassis->moveDistance(0.3_m);
  chassis->turnAngle(150_deg);
  chassis->moveDistance(2.6_m);
  backliftController->setTarget(-80);
  chassis->moveDistance(-1.4_m);
  chassis->moveDistance(0.3_m);
  chassis->setMaxVelocity(100);
  chassis->turnAngle(-487_deg);
  chassis->moveDistance(-1.6_m);
  backliftController->setTarget(85);
  pros::delay(100);
  chassis->setMaxVelocity(200);
  chassis->moveDistance(3.1_m);
  chassis->turnAngle(-386_deg);
  chassis->setMaxVelocity(100);
  chassis->moveDistance(6.6_m);
  chassis->moveDistance(0.4_m);
  chassis->setMaxVelocity(300);
  chassis->turnAngle(80_deg);
  chassis->moveDistance(3.5_m);
  chassis->moveDistance(-0.8_m);
  chassis->turnAngle(550_deg);
  backliftController->setTarget(-80);
  chassis->turnAngle(510_deg);
  chassis->setMaxVelocity(160);
  chassis->moveDistance(-1.55_m);
  backliftController->setTarget(80);
  chassis->moveDistance(2.2_m);
  chassis->setMaxVelocity(80);
  chassis->turnAngle(-485_deg);
  chassis->setMaxVelocity(280);
  chassis->moveDistance(7_m);
  chassis->turnAngle(-20_deg);
  chassis->moveDistance(1_m);
  backliftController->setTarget(-80);
  chassis->moveDistance(-0.2_m);
  chassis->turnAngle(-491_deg);
  chassis->moveDistance(-3_m);
/*  chassis->moveDistance(0.4_m);
  chassis->turnAngle(-140_deg);
  chassis->moveDistance(2.2_m);
  chassis->moveDistance(-1.2_m);
  chassis->turnAngle(280_deg);
  chassis->moveDistance(1.6_m);
  liftController->setTarget(2300);
  chassis->setMaxVelocity(100);
  chassis->moveDistance(-2_m);
  chassis->setMaxVelocity(70);
  chassis->turnAngle(450_deg);
  chassis->setMaxVelocity(500);
  chassis->moveDistance(6.5_m);
  liftController->setMaxVelocity(40);
  liftController->setTarget(2000);
  chassis->waitUntilSettled();
  liftController->setTarget(-100);
  chassis->setMaxVelocity(600);
  chassis->moveDistance(-2_m);*/
  //chassis->turnAngle(450_deg);
}

void blueLeftCorner(){
    liftController->setTarget(500);
}

void blueRightCorner(){

}
void autonomous() {
  //redLeftCorner();
  redRightCorner();
  //blueRightCorner();
  //blueLeftCorner();
}
