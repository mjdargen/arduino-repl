#include "arduino.h"
#include <sys/time.h>

struct timespec start;
dummySerial Serial;

int random(int start, int end) {
  int num = 0;
  if (start < end) {
    num = (start + rand()) % end;
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
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  setup();
  while(1) {loop();}
}

unsigned long millis() {
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC_RAW, &now);
  return ((now.tv_sec + 1.0e-9*now.tv_nsec) - (start.tv_sec + 1.0e-9*start.tv_nsec))*1000;
} 

unsigned long micros() {
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC_RAW, &now);
  return ((now.tv_sec + 1.0e-9*now.tv_nsec) - (start.tv_sec + 1.0e-9*start.tv_nsec))*1000000;
} 