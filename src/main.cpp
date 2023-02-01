/**
 * @file main.cpp
 * @author Nilusink
 * @brief main file for the project
 * @version 0.1
 * @date 2023-02-01
 * 
 * @copyright Copyright FrenchBakery (c) 2023
 * 
 */
#include <drivers/tiramisu/grepper/grepper.hpp>
#include <iostream>


int main()
{
    Digital end_sensor(0);
    Motor l_motor(0);
    Motor r_motor(1);
    Servo grab_servo(0);

    Gripper gripper(grab_servo, l_motor, r_motor, end_sensor);

    // tests
    float curr_val;
    for (;;)
    {
        std::cout << "servo value (cm): ";
        std::cout.flush();
        std::cin >> curr_val;
        std::cout << "\n";

        gripper.setClawPositionCm(curr_val);
    }

    return 0;
}
