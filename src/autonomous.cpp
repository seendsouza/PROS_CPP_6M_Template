#include "main.h"
#include "global.h"
#include "autonomous.h"

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

void drive_straight (int straight_ticks, int speed) {
    left_front_wheels.move_relative(straight_ticks, speed); 
    left_center_wheels.move_relative(straight_ticks, speed); 
    left_back_wheels.move_relative(straight_ticks, speed);
    right_front_wheels.move_relative(straight_ticks, speed); 
    right_center_wheels.move_relative(straight_ticks, speed);
    right_back_wheels.move_relative(straight_ticks, speed);
}

void autonomous() {
    drive_straight(1000, 100);
}
