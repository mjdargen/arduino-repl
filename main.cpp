#include "arduino.h"

dummySerial Serial;

int random(int start, int end) {
  int num = 0;
  if (start < end) {
    int num = (start + rand()) % end;
    while (!((num >= start) && (num < end))) {
      num = (start + rand()) % end;
    }
  }
  else {
    num = end;
  }
  return num;
}

int main() {
  setup();
  while(1) {loop();}
}