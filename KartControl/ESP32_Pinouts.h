#pragma once

#define DEBUG_LED_PIN 13

/** GPS **/
// I2C
    // SDA 21
    // SCL 22

/** DigiPot - MCP45HVX1 **/
// I2C
    // SDA 21
    // SCL 22

/** Throttle Switch **/
    #define THROTTLE_SWITCH_PIN

/** SD Card Reader **/
// SPI
    // SDO 23
    // SDI 19
    // CLK 18
    // CS  5

/** Brake **/
    #define BRAKE_PIN_1 32
    #define BRAKE_PIN_2 33
    #define BRAKE_POT_PIN 35

/** Odometer - Hall Sensor **/
    #define HALL_PIN 16

/** Steering Motor - Roboclaw **/
    // RX 14
    // TX 12

/** Box Switch **/
    #define BOX_SWITCH_PIN 34