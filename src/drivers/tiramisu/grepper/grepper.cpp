/**
 * @file grepper.cpp
 * @author Nilusink
 * @version 0.1
 * @date 2023-02-01
 * 
 * @copyright Copyright FrenchBakery (c) 2023
 * 
 */
#include "grepper.hpp"


/*
    // cpp refernce: array
    measurement points for the gripper
    0: 10.3
    10: 10.25
    20: 10.2
    30: 10
    40: 9.5
    45: 8.6
    50: 7.8
    55: 7.2
    60: 5.7
    70: 4
    75: 3.6
    80: 1.8
    90: 1
    100: 0
*/
const double gripperCmValues[14] = {
    10.3,
    10.25,
    10.2,
    10,
    9.5,
    8.6,
    7.8,
    7.2,
    5.7,
    4,
    3.6,
    1.8,
    1,
    0
};


const int gripperServoPercent[14] = {
    0,
    10,
    20,
    30,
    40,
    45,
    40,
    44,
    60,
    70,
    75,
    80,
    90,
    100
};


float Gripper::makeGripperLinear(float value)
{   // value in cm
    if (!(gripperCmValues[13] <= value && value < gripperCmValues[0])) return 0;  // not in range

    // find first point larger than the desired value
    int i;
    for (i = 13; i > -1; i--)
    {
        if (gripperCmValues[i] > value) break;
    }

    std::cout << "v1: " << gripperCmValues[i] << "\nv2: " << gripperCmValues[i+1] << "\n";

    // interpolate (lerp)
    float actualVal = map(value, gripperCmValues[i+1], gripperCmValues[i], gripperServoPercent[i+1], gripperServoPercent[i]);

    return actualVal;

}

Gripper::Gripper(Servo &s, Motor &left_motor, Motor &right_motor, Digital &end_switch)
    : servo(s), e_switch(end_switch), l_motor(left_motor), r_motor(right_motor), active(false), claw_position(0), closed_pos(160), open_pos(1200)
{
    // update the claw to the starting position
    if (!servo.isEnabled())
        servo.enable();

    setClawPositionCm(claw_position);
}

void Gripper::grabUntilEnd(int speed)
{
    // only grab if nothing is already grabbed
    if (active)
        return;

    // turn motors on
    r_motor.motor(-speed);
    l_motor.motor(-speed);

    // wait until the end switch is activated
    while (!e_switch.value())
    {
        msleep(10);
    };

    // turn motors back off
    l_motor.off();
    r_motor.off();

    // set current state
    active = true;
}

void Gripper::setClawPositionCm(float cm_value)
{
    double actual_percent = makeGripperLinear(cm_value);

    std::cout << "cm: " << cm_value << "\npercent: " << actual_percent << "\n\n\n";

    // calculate actual servo position
    int servo_pos = (int)map(actual_percent, 0, 100, open_pos, closed_pos);

    std::cout << servo_pos << "\n";

    // update the servo
    servo.setPosition(servo_pos);

    // update state
    claw_position = actual_percent;
}

void Gripper::setClawPosition(float percent_closed)
{
    // if the given position is out of range
    if (!(0 <= percent_closed && percent_closed <= 100))
        return;

    double cm_pos = (percent_closed / 100) * gripperCmValues[0];

    setClawPositionCm(cm_pos);
}

void Gripper::openClaw()
{
    setClawPositionCm(0);
}

void Gripper::closeClaw()
{
    setClawPositionCm(100);
}

void Gripper::release(int speed, int release_time)
{
    // turn motors on
    r_motor.motor(speed);
    l_motor.motor(speed);

    // wait time
    msleep(release_time*1000);

    // turn motors off
    r_motor.off();
    l_motor.off();

    // set current state
    active = false;
}


// getters
bool Gripper::getActive()
{
    return active;
}

int Gripper::getClawPosition()
{
    return claw_position;
}

bool Gripper::getSensorValue()
{
    return e_switch.value();
}
