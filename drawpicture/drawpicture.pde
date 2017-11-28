// Sonali Mahendran and Alisa Momin
// BIOE 421 Microcontroller Applications
// Final Project: SnapPainter
// Description: This proecessing code allows the user to paint 
// their own filter for their videos using a Circuit Playground-
// based mouse with a color functionality. The filter 
// is then saved as a PNG with a transparent background.

import processing.serial.*;
PGraphics img;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
float num;

void setup() {
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  size(640, 360); // set size of the canvas
  //background(102);
  img = createGraphics(width, height);
}

void draw() {
// Following part sets colors based on captouch sensors touched 
  if ( myPort.available() > 0) 
  {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
  } 
  println(val); //print it out in the console
  if (val != null) {
    num = float(val);
  
  if (num == 3) {
    int r = 236;
    int g = 51;
    int b = 116;
    img.stroke(r, g, b);
  } else if (num == 2) {
        int r = 255;
    int g = 0;
    int b = 0;
    img.stroke(r, g, b);
  }
  else if (num == 0) {
    int r = 255;
    int g = 64;
    int b = 0;
    img.stroke(r, g, b);
  }
    else if (num == 1) {
    int r = 247;
    int g = 240;
    int b = 34;
    img.stroke(r, g, b);
  }
     else if (num == 12) {
    int r = 0;
    int g = 255;
    int b = 0;
    img.stroke(r, g, b);
  }
       else if (num == 6) {
    int r = 16;
    int g = 188;
    int b = 171;
    img.stroke(r, g, b);
  }
    else if (num == 9) {
    int r = 0;
    int g = 0;
    int b = 255;
    img.stroke(r, g, b);
  }
  else if (num == 10) {
    int r = 93;
    int g = 19;
    int b = 178;
    img.stroke(r, g, b);
  }   else if (num == 4) { // if right button is pressed and the switch is on the right, the drawing is saved
       img.endDraw();
       img.save("Filter.png");
       exit();
  } 
  }
// If the button of the "mouse" is pressed, then user can draw using the Circuit Playground
  if (mousePressed == true) {
    img.beginDraw();
    img.line(mouseX, mouseY, pmouseX, pmouseY); // Mouse cursor coordinates
    img.endDraw();
    image(img, 0, 0);
  }
}