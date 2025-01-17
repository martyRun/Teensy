/*

  choose your robot type, baud rates, pin definitions etc.

*/

#ifndef MOWER_H
#define MOWER_H

#include <Arduino.h>
#include "robot.h"
#include "drivers.h"


//*****************possible list of motor driver set to :****************
// 1 for brushless BL500W Driver
// 2 for DC L298N Driver
// 3 for DC BTS7960 Driver
#define LEFT_MOTOR_DRIVER 1  //never mix BL and DC on drive motor
#define RIGHT_MOTOR_DRIVER 1
#define MOW_MOTOR_DRIVER 1

#define PWM_FREQUENCY_BL500W  20000 //
#define PWM_FREQUENCY_L298N  10000 
#define PWM_FREQUENCY_BTS7960  10000


#define BUMPER_IS_SWITCH false  // set to true if the bumper is a single ON/OFF switch
#define BUMPER_REAR_EXIST false  // set to true to manage the rear bumper connected on CAN3 J20 connector

#define START_BUTTON_IS_NC true //if button is normaly closed

#define INA226_MOW2_PRESENT false
#define INA226_MOW3_PRESENT false

#define ODOMETRY_ONLY_RISING false
//***********************************************************************

//**********************       COMPASS         **************************
//#define COMPASS_IS HMC5883L
#define COMPASS_IS QMC5883L
//***********************************************************************

//#define Console Serial
#define CONSOLE_BAUDRATE    115200       // baudrate used for serial debug
#define track_ClockWise false    //tracking wire direction
#define RaspberryPIPort Serial  //The PI is connected over USB cable

#define Bluetooth Serial1  // Ardumower default OK for ESP32 or HC05
#define BLUETOOTH_BAUDRATE  19200     // baudrate used for communication with Bluetooth module (Ardumower default: 19200)

#define GpsPort Serial3  // GPS 

#define D5VoltageDrop 0.8

// ---- choose only one perimeter signal code ----
#define SIGCODE_1  // Ardumower default perimeter signal
//#define SIGCODE_2  // Ardumower alternative perimeter signal
//#define SIGCODE_3  // Ardumower alternative perimeter signal




// ------ pins---------------------------------------

#define pinMotorLeftEnable  5         // EN motors enable
#define pinMotorLeftPWM 7          // M1_IN1 left motor PWM pin
#define pinMotorLeftDir 6         // M1_IN2 left motor Dir pin
#define pinMotorRightEnable  2        // EN motors enable
#define pinMotorRightPWM  4        // M2_IN1 right motor PWM pin
#define pinMotorRightDir 3        // M2_IN2 right motor Dir pin
#define pinMotorMowEnable 8       // EN mower motor enable      (if using MOSFET/L298N, keep unconnected)
#define pinMotorMowPWM 10           // M1_IN1 mower motor PWM pin (if using MOSFET, use this pin)
#define pinMotorMowDir 9          // M1_IN2 mower motor Dir pin (if using MOSFET, keep unconnected)
#define pinBumperLeft 35          // bumper pins
#define pinBumperRight 36
#define pinBumperRearLeft 30          // bumper pins
#define pinBumperRearRight 31
#define pinSonarRightTrigger 29  //BBER10
#define pinSonarRightEcho A13
#define pinSonarLeftTrigger 28   //BBER10
#define pinSonarLeftEcho A12


#define pinPerimeterRight A8       // perimeter
#define pinPerimeterLeft A9
#define pinBuzzer 37               // Buzzer
#define pinButton 38             // digital ON/OFF button
#define pinBatterySwitch 33         // battery-OFF switch   
#define pinChargeEnable 34          // charge relay
#define pinOdometryLeft 12     // left odometry sensor
#define pinOdometryRight 11   // right odometry sensor  
#define pinRain 39                 // rain sensor
#define pinUserOut1 13          // remote control mower motor
#define pinUserOut2 32          // remote control steering 
#define pinUserOut3 A16        // remote control speed

// ------- ultrasonic config ---------------------------------------------------------
#define NO_ECHO 0

/*
  standard robot chassis
*/

class Mower : public Robot
{
  public:
    Mower();
    virtual void setup(void);
    virtual void setActuator(char type, int value);
};
extern Mower robot;
#endif
