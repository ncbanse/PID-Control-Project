/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(2, 3);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
}
double desiredAngle = 360;
long oldPosition  = -999;
double desiredPosition = (desiredAngle * 28)/360;
double throtGain = 0.01;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    long error = desiredPosition - newPosition;
    double throtle = (error * throtGain) + 0.5;
    if (throtle > 1) {
      throtle = 1;
    } if (throtle < 0) {
      throtle = 0;
    }
    Serial.print(error);
    Serial.print("  ");
    Serial.print(throtle);
    Serial.print("  ");
    Serial.println(newPosition);
  }
}