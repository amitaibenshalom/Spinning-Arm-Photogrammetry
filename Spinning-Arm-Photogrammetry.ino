#include "Basic_Routines.h"

void setup() {

  Serial.begin(BAUDRATE);
  delay (1000);

  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(LED_OUT, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  homming();
}

void loop() {

  if (digitalRead(BUTTON_PIN) == LOW) {
    // Serial.println("Button pressed...");
    isPressed = true;
    if (millis() > last_pulse_time + rate) {
      one_step(false);
      last_pulse_time = millis();
      print_steps();
    }
  }
  // if (digitalRead(BU))
}
