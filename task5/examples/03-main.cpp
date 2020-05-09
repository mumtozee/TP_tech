//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include <Weather.h>
#include <iostream>
int main() {
  Weather weather;
  weather.SetApiKey("Your api key");

  std::cout << weather.GetTemperature("London");
}