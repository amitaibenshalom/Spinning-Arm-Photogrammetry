#ifndef CONSTS.h
#define CONSTS.h
#include <Arduino.h>

#define DIR_PIN 4
#define STEP_PIN 5
#define ENABLE_PIN 6
#define LED_OUT 13
#define BUTTON_PIN A2

const uint8_t START_LED_BLINK_NUMBER = 3;
const uint16_t START_LED_BLINK_ON = 100;//ms
const uint16_t START_LED_BLINK_OFF = 200;//ms

const float MIN_ANGLE = 0;
const float MAX_ANGLE = 90;

const uint16_t DIRECTION_CHANGE_WAIT_TIME = 5; //[ms] time wait/stop move between change direction to avoid loos steps
const uint16_t MIN_RATE = 3; //ms - minimum time between steps pulses - faster speed
const uint16_t MAX_RATE = 150; //ms - maximum, time between steps pulses - slower speed
const uint16_t HOMMING_RATE  = MIN_RATE ; 
const float TOLERANCE = 0.5;// ratio to mm per pulse tolerance for not move 

float angle_per_pulse = 360.0/800;

bool Is_destination_done = true;
int16_t steps = 0;
int16_t HOMMING_STEPS = (MAX_ANGLE - MIN_ANGLE)/angle_per_pulse;
int16_t STEPS_TO_CENTER = (MAX_ANGLE-MIN_ANGLE)/angle_per_pulse /2;

float angle = 0;
float destination = 0;
float delta = 0;
float max_delta = TOLERANCE * angle_per_pulse;

uint16_t rate = 3;

bool motor_direction = false;
uint32_t last_pulse_time = 0;


bool isPressed = false;


#define BAUDRATE (115200)

#endif
