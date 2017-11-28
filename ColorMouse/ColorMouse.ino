
// Alisa Momin and Sonali Mahendran, Team 6
// BIOE 421 Microcontroller Applications
// Final Project: SnapPainter

// Circuit Playground Accelerometer Mouse Example
// Tilt Circuit Playground left/right and up/down to move your mouse, and
// press the left and right push buttons to click the mouse buttons!  Make sure
// the slide switch is in the on (+) position to enable the mouse, or slide into
// the off (-) position to disable it.  By default the sketch assumes you hold
// Circuit Playground with the USB cable coming out the top.
// Author: Tony DiCola
// License: MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_CircuitPlayground.h>
#include <Mouse.h>
#include <Wire.h>
#include <SPI.h>

#define XACCEL_MIN 0.1      // Minimum range of X axis acceleration, values below
// this won't move the mouse at all.
#define XACCEL_MAX 8.0      // Maximum range of X axis acceleration, values above
// this will move the mouse as fast as possible.
#define XMOUSE_RANGE 25.0   // Range of velocity for mouse movements.  The higher
// this value the faster the mouse will move.
#define XMOUSE_SCALE 1      // Scaling value to apply to mouse movement, this is
// useful to set to -1 to flip the X axis movement.
#define YACCEL_MIN XACCEL_MIN
#define YACCEL_MAX XACCEL_MAX
#define YMOUSE_RANGE XMOUSE_RANGE
#define YMOUSE_SCALE 1
#define FLIP_AXES true
#define CAP_THRESHOLD    300  // Threshold for a capacitive touch (higher = less sensitive).
#define CAP_SAMPLES      20   // Number of samples to take for a capacitive touch read.
int r;
int g;
int b;
int num;

float lerp(float x, float x0, float x1, float y0, float y1) {
  // Check if the input value (x) is outside its desired range and clamp to
  // those min/max y values.
  if (x <= x0) {
    return y0;
  }
  else if (x >= x1) {
    return y1;
  }
  // Otherwise compute the value y based on x's position within its range and
  // the desired y min & max.
  return y0 + (y1 - y0) * ((x - x0) / (x1 - x0));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
  Mouse.begin();

  //Set LEDs to represent our color paint palette
  CircuitPlayground.setPixelColor(0, 236,   51,  116); //pink
  CircuitPlayground.setPixelColor(1, 255,   0,     0); //red
  CircuitPlayground.setPixelColor(3, 255,   64,    0); //orange
  CircuitPlayground.setPixelColor(4, 128,  128,   0); //yellow
  CircuitPlayground.setPixelColor(5,   0,  255,    0); //green
  CircuitPlayground.setPixelColor(6,   16,   188,  171); //teal
  CircuitPlayground.setPixelColor(8,   0,    0,  255); //blue
  CircuitPlayground.setPixelColor(9, 93, 19, 178); //purple
}

void loop() {
  // put your main code here, to run repeatedly:
  capt();
  if (!CircuitPlayground.slideSwitch()) {
    return;
  }


  // Grab initial left & right button states to later check if they are pressed
  // or released.  Do this early in the loop so other processing can take some
  // time and the button state change can be detected.
  boolean left_first = CircuitPlayground.leftButton();
  boolean right_first = CircuitPlayground.rightButton();

  // Grab x, y acceleration values (in m/s^2).
  float x = CircuitPlayground.motionX();
  float y = CircuitPlayground.motionY();
  // Use the magnitude of acceleration to interpolate the mouse velocity.
  float x_mag = abs(x);
  float x_mouse = lerp(x_mag, XACCEL_MIN, XACCEL_MAX, 0.0, XMOUSE_RANGE);
  float y_mag = abs(y);
  float y_mouse = lerp(y_mag, YACCEL_MIN, YACCEL_MAX, 0.0, YMOUSE_RANGE);
  // Change the mouse direction based on the direction of the acceleration.
  if (x < 0) {
    x_mouse *= -1.0;
  }
  if (y < 0) {
    y_mouse *= -1.0;
  }
  // Apply any global scaling to the axis (to flip it for example) and truncate
  // to an integer value.
  x_mouse = floor(x_mouse * XMOUSE_SCALE);
  y_mouse = floor(y_mouse * YMOUSE_SCALE);

  // Move mouse.
  if (!FLIP_AXES) {
    // Non-flipped axes, just map board X/Y to mouse X/Y.
    Mouse.move((int)x_mouse, (int)y_mouse, 0);
  }
  else {
    // Flipped axes, swap them around.
    Mouse.move((int)y_mouse, (int)x_mouse, 0);
  }

  // Small delay to wait for button state changes and slow down processing a bit.
  delay(10);

  // Grab a second button state reading to check if the buttons were pressed or
  // released.
  boolean left_second = CircuitPlayground.leftButton();
  boolean right_second = CircuitPlayground.rightButton();

  // Check for left button pressed / released.
  if (!left_first && left_second) {
    // Low then high, button was pressed!
    Mouse.press(MOUSE_LEFT);
  }
  else if (left_first && !left_second) {
    // High then low, button was released!
    Mouse.release(MOUSE_LEFT);
  }
  // Check for right button pressed / released.
  if (!right_first && right_second) {
    // Low then high, button was pressed!
    Mouse.press(MOUSE_RIGHT);
  }
  else if (right_first && !right_second) {
    // High then low, button was released!
    Mouse.release(MOUSE_RIGHT);
  }
}

void capt() {    // this function just senses the sensors that are pushed and saves the numbers corresponding to the sensors in an array

  if (CircuitPlayground.readCap(3, CAP_SAMPLES) >= CAP_THRESHOLD) {
    // Serial.println("pink");
    int num = 3;
    Serial.println(num);
  }
  else if (CircuitPlayground.readCap(2, CAP_SAMPLES) >= CAP_THRESHOLD) {
    int num = 2;
    Serial.println(num);

  }
  else if (CircuitPlayground.readCap(0, CAP_SAMPLES) >= CAP_THRESHOLD) {
    int num = 0;
    Serial.println(num);
  }
  else if (CircuitPlayground.readCap(1, CAP_SAMPLES) >= CAP_THRESHOLD) {
    int num = 1;
    Serial.println(num);

  }
  else if (CircuitPlayground.readCap(12, CAP_SAMPLES) >= CAP_THRESHOLD) {
    int num = 12;
    Serial.println(num);

  }
  else if (CircuitPlayground.readCap(6, CAP_SAMPLES) >= CAP_THRESHOLD) {
    int num = 6;
    Serial.println(num);
  }
  else if (CircuitPlayground.readCap(9, CAP_SAMPLES) >= CAP_THRESHOLD) {
    int num = 9;
    Serial.println(num);
  }
  else if (CircuitPlayground.readCap(10, CAP_SAMPLES) >= CAP_THRESHOLD) {
    int num = 10;
    Serial.println(num);
  }

  if (!CircuitPlayground.slideSwitch() && CircuitPlayground.rightButton()) {
    int num = 4;
    Serial.println(num);
  }
}

