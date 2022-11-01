void setup() {
  // put your setup code here, to run once:
  double angle = 0;
  int encodeRes = 2^12 * 4;
  double angleIn = 90;
  double encodeFreq = 5;
}

void loop() {
  bool digitalRead(2) = encode1;
  bool digitalRead(3) = encode2;
  delay(5);
  if (encode1 != digitalRead(2) || encode2 != digitalRead(3)) {
    angle = angle + 360/encodeRes;
  }

}
