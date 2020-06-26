#include "arduino.h"

// put your setup code here, to run once:
void setup() {
  // Serial.begin(9600);
  Serial.print("Hello World!");
  Serial.println("Hello World!\n");
  Serial.print("Hello World!");
  randomSeed(A0);
}

// put your main code here, to run repeatedly:
void loop() {
  int num = random(0,50);
  // Serial.println(num);
  Serial.print(2);
  delay(1000);
}