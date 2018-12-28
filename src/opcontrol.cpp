#include "main.h"
#include "global.h"
#include "autonomous.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

// Analog
// Drives

void arcade_drive() {
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_LEFT_X);
    int left = power + turn;
    int right = power - turn;

    left_front_wheels.move(left);
    left_center_wheels.move(left);
    left_back_wheels.move(left);
    right_front_wheels.move(right);
    right_center_wheels.move(right);
    right_back_wheels.move(right);
}

void split_arcade_drive() {
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    int left = power + turn;
    int right = power - turn;

    left_front_wheels.move(left);
    left_center_wheels.move(left);
    left_back_wheels.move(left);
    right_front_wheels.move(right);
    right_center_wheels.move(right);
    right_back_wheels.move(right);
}

void tank_drive() {
    left_front_wheels.move(master.get_analog(ANALOG_LEFT_Y));
    left_center_wheels.move(master.get_analog(ANALOG_LEFT_Y));
    left_back_wheels.move(master.get_analog(ANALOG_LEFT_Y));
    right_front_wheels.move(master.get_analog(ANALOG_RIGHT_Y));
    right_center_wheels.move(master.get_analog(ANALOG_RIGHT_Y));
    right_back_wheels.move(master.get_analog(ANALOG_RIGHT_Y));
}

// Digital
// Miscellaneous

void auton() {
    if (master.get_digital(DIGITAL_A)) {
        autonomous();
   }
}
void catapult() {
    if (master.get_digital(DIGITAL_L1)) {
        catapult_motor.move_velocity(200);
    } else if (master.get_digital(DIGITAL_L2)) {
        catapult_motor.move_velocity(-200);
    } else {
        catapult_motor.move_velocity(0);
    }   
}

void lift() {
    if (master.get_digital(DIGITAL_R1)) {
        lift_motor.move_velocity(200);
    } else if (master.get_digital(DIGITAL_R2)) {
        lift_motor.move_velocity(-200);
    } else {
        catapult_motor.move_velocity(0);
    }   

}

void opcontrol() {
    while (true) {
        tank_drive();
        catapult();
        lift();
        auton();
		pros::delay(20);
	}
}
