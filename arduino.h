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
    void print(int val) {
      std::cout << value;
    }
    void print(const std::string &s) {
      std::cout << s;
    }
    // template<typename T>
    // void print(T value) {
    //   if constexpr (std::is_same_v<std::decay_t<T>, int>) {
    //       std::cout << value;
    //   }
    //   else if constexpr (std::is_same_v<std::decay_t<T>, bool>) {
    //       std::cout << value;
    //   }
    //   else if constexpr (std::is_same_v<std::decay_t<T>, float>) {
    //       std::cout << value;
    //   }
    //   else if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
    //       std::cout << value;
    //   }
    // }
    template<typename T>
    void println(T value) {
      if constexpr (std::is_same_v<std::decay_t<T>, int>) {
          std::cout << value;
          std::cout << "\n";
      }
      else if constexpr (std::is_same_v<std::decay_t<T>, bool>) {
          std::cout << value;
          std::cout << "\n";
      }
      else if constexpr (std::is_same_v<std::decay_t<T>, float>) {
          std::cout << value;
          std::cout << "\n";
      }
      else if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
          std::cout << value;
          std::cout << "\n";
      }
    }
};

extern dummySerial Serial;
void setup();
void loop();
int random(int start, int end);