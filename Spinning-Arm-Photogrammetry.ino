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
    clickable = true;
  }

  if (clickable && digitalRead(BUTTON_PIN) == LOW) {
    clickable = false;

    //start photogrammetry routine:
    //move to the side
    hard_move(MAX_ANGLE);
    delay(DELAY_AT_STOP);
    Keyboard.write(48);  // 00ABCDEFGHIJKL
    send_keys = true;
    current_key = starting_key;
    next_angle_for_image = MAX_ANGLE;
    hard_move(MIN_ANGLE);
    delay(DELAY_AT_STOP);
    send_keys = false;
    hard_move(0);
  }
}
