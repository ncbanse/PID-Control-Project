#include <Encoder.h>
Encoder myEnc(2, 3);
long encoderRes = 28;

#include <VescUart.h>
VescUart UART;

float duty = 0.0;

void setup() {
  Serial.begin(9600);  
  while (!Serial) {;}
  UART.setSerialPort(&Serial);
  UART.setDuty(duty);
}

int analogPin = A3;
long oldPosition  = -999;
double throtGain = 0.0025;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
  }
  double voltage = (5 * analogRead(analogPin)/1023.0);
  long error = ((encoderRes * voltage) * 5) - newPosition;
  duty = (error * throtGain);
  if (duty > 1) {
    duty = 1;
  } if (duty < -1) {
    duty = -1;
  }
  UART.setDuty(duty);
}
