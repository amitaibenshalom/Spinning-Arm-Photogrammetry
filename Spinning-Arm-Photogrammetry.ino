#include "Basic_Routines.h"

void setup() {

  Serial.begin(BAUDRATE);
  Keyboard.begin();
  delay (1000);

  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(LED_OUT, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  homming();
}

void loop() {

  delay(5); // delay for IO's to stable
  
  if (millis() > last_click_time + delay_between_clicks) {
    if (digitalRead(BUTTON_PIN) == LOW) {
        if (millis() > last_pulse_time + rate) {
          one_step(false);
          last_pulse_time = millis();
          // print_steps();
        }
      // if (!isPressed) {
      //   Serial.println("Button pressed...");
      //   // isPressed = true;
      // }
    }
      // last_click_time = millis();

    else {
      isPressed = false; 


    }
  }


}
