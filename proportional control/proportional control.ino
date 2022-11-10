/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

Encoder myEnc(2, 3);

#include <Servo.h>

byte servoPin = 9;
Servo servo;

//int RX = 0;
//int TX = 1;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);

  servo.writeMicroseconds(1500); // send "stop" signal to ESC.

  delay(7000); // delay to allow the ESC to recognize the stopped signal
}

long oldPosition  = -999;
double desiredPosition = 2800;
double throtGain = 0.001;

void loop() {
  while (Serial.available() == 0);
  int val = Serial.parseInt(); 
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    long error = desiredPosition - newPosition;
    double throtle = (error * throtGain);
    if (throtle > .5) {
      throtle = .5;
    } if (throtle < -.5) {
      throtle = -.5;
    }
    throtle += .5;
    throtle = throtle * 800;
    throtle += 1100;
    val = throtle;
    Serial.print(error);
    Serial.print("  ");
    Serial.print(throtle / 255);
    Serial.print("  ");
    Serial.print(throtle);
    Serial.print("  ");
    Serial.println(newPosition);
    servo.writeMicroseconds(val); // Send signal to ESC.
  }
}