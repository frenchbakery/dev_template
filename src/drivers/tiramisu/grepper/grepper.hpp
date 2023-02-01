/**
 * @file grepper.hpp
 * @author Nilusink
 * @brief driver for Tiramisu's grepper
 * @version 0.1
 * @date 2023-02-01
 * 
 * @copyright Copyright FrenchBakery (c) 2023
 * 
 */
#include <kipr/digital.hpp>
#include <kipr/motors.hpp>
#include <kipr/servo.hpp>
#include <kipr/util.hpp>
#include <utils.hpp>
#include <iostream>


/**
 * @brief driver for Tiramisu's gripper
 * 
 */
class Gripper
{
    private:
        Servo &servo;
        Motor &l_motor;
        Motor &r_motor;
        Digital &e_switch;

        bool active;
        float claw_position;

        const int closed_pos;
        const int open_pos;

        /**
         * @brief since the gripper's mechianism isn't linear, we need a function to propperly define how far closed the gripper should be
         * 
         * @param value non-linear value
         * @return float - linear value
         */
        float makeGripperLinear(float value);

    public:
        Gripper(Servo &s, Motor &left_motor, Motor &right_motor, Digital &end_switch);

        /**
         * @brief turns on motors until the end switch is triggered
         * 
         * @param speed how fast the motors should be on
         */
        void grabUntilEnd(int speed = 100);

        /**
         * @brief closes the grabber claw
         * 
         * @param percent_closed cm range: 0..10.3, how far the claw should close (0...closed, 10.3...open)
         */
        void setClawPositionCm(float cm_value);

        /**
         * @brief closes the grabber
         * 
         * @param percent_closed range: 0..100, how far the claw should close (0...open, 100...closed)
         */
        void setClawPosition(float percent_closed);

        /**
         *  @brief fully open the claw
        */
        void openClaw();

        /**
         *  @brief fully close the claw
        */
        void closeClaw();

        /**
         * @brief release anything grabbed
         * 
         * @param speed motor speed for grabbing
         * @param release_time how long the motors should release
         */
        void release(int speed = 100, int release_time = 3);

        // getters
        /**
         * @brief Get the active object
         * 
         * @return true - something is grabbed \\
         * @return false - nothing is grabbed
         */
        bool getActive();

        /**
         * @brief Get the claws position
         * 
         * @return int 
         */
        int getClawPosition();

        /**
         * @brief Get the sensor value
         * 
         * @return true the end sensor is activated \\
         * @return false the end sensor isn't activated
         */
        bool getSensorValue();
};
