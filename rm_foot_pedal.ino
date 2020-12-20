
// Detect the falling edge

// Include the Bounce2 library found here :
// https://github.com/thomasfredericks/Bounce-Arduino-Wiring
#include <Bounce2.h>

#define NEXT_KEY KEY_RIGHT_ARROW
#define PREV_KEY KEY_LEFT_ARROW
#define SWITCH_PIN 2

Bounce* bouncer;
unsigned long last_keypress = 0;
unsigned long now = 0;
bool press_key = false;

void setup() {
  // Setup the button with an internal pull-up :
  pinMode(SWITCH_PIN,INPUT_PULLUP);
  bouncer = new Bounce();
  // After setting up the button, setup the Bounce instance :
  bouncer->attach(SWITCH_PIN);
  bouncer->interval(50);
}

void loop() {
  // Update the Bounce instance :
  bouncer->update();
  now = millis();
  if (press_key && now - last_keypress > 300) {
    Keyboard.press(NEXT_KEY);
    delay(10);
    Keyboard.releaseAll();
    press_key = false;
  }
  // Call code if Bounce fell (transition from HIGH to LOW) :
  if ( bouncer->fell() ) {
   // check if we hit the same key within the last 300 ms
   if (now - last_keypress < 300) {
     Keyboard.press(PREV_KEY);
     delay(10);
     Keyboard.releaseAll();
     press_key = false;
   } else {
     press_key = true;
   }
   last_keypress = now;
  }
}
