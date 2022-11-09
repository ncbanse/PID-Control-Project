/*
  Name:    setCurrent.ino
  Created: 19-08-2018
  Author:  SolidGeek
  Description: This is a very simple example of how to set the current for the motor
*/

#include <VescUart.h>

/** Initiate VescUart class */
VescUart UART;

float current = 5.0; /** The current in amps */
float duty = 0.2;

void setup() {
  Serial.begin(9600);
  /** Setup UART port (Serial1 on Atmega32u4) */
  
  while (!Serial) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&Serial);
}

void loop() {
  
  /** Call the function setCurrent() to set the motor current */
  /**while (current >= 0) {
    UART.setCurrent(current);
    dellay(50);
    current -= .1;*/
  }
  
  // UART.setBrakeCurrent(current);
  while (duty >= 0) {
    UART.setDuty(duty);
    dellay(50);
    duty -= 0.01;
  }

}