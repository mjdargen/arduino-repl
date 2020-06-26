#include <unistd.h>
#include <type_traits>
#include <string>
#include <iostream>

#define randomSeed(d) ({\
  time_t t;\
  srand((unsigned) time(&t));\
})
#define A0  1

#define delayMicroseconds(us) usleep(us)
#define delay(ms) usleep(ms*1000)

class dummySerial{
  public:
    void begin(int baud) {
      ;
    }
    template<typename T> static void print(T t) {
      std::cout << t;
      std::cout.flush();
    }
    template<typename T> static void println(T t) {
      std::cout << t;
      std::cout << std::endl;
      std::cout.flush();
    }
};

extern dummySerial Serial;
void setup();
void loop();
int random(int start, int end);
unsigned long millis();
unsigned long micros();