#include "Functions.h"

#include <stdexcept>
int Add(int x, int y) {
    return x + y;
}

bool IsLeap(int year) {
  if (year <= 0) {
    throw std::invalid_argument("Year must be greater than 0");
  }

  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
    return true;
  }
  return false;
}




