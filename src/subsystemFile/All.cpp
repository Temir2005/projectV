#include "main.h"
void setIntake(int power){
  intake = power;
}
void setgoRight(int right){
  backLeft = right;
  frontLeft = right;
}
void setHigh(int power){
  krutilka = power;
}
void setAll(int power1){
  backlift = power1;
}
void setLift(int power){
  liftLeft = power;
  liftRight = power;
}
void setAllMotors(){
    int power1 = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setAll(power1);
}
void setLift(){
  int power1 = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
  setLift(power1);
}
void setIntake(){
  int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
  setIntake(power);
}
void allkrutilkas(int degrees, int voltage){
  int direction = abs(degrees) / degrees;
  krutilka.tare_position();
  while(abs(krutilka.get_position()) < abs(degrees)){
    setAll(voltage * direction);
    pros::delay(10);
  }
  setAll(0);
}
void lift(int degrees, int voltage){
  int direction = abs(degrees) / degrees;
  liftLeft.tare_position();
  while(abs(liftLeft.get_position()) < abs(degrees)){
    setLift(voltage * direction);
    pros::delay(10);
  }
  setLift(0);
}
