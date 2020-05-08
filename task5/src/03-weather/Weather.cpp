//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "Weather.h"

#include "cpr/cpr.h"


json Weather::GetResponseForCity(const std::string &city) {
  auto response = Get(city);

  if (response.status_code != 200) {
    throw std::invalid_argument("Api error. City is bad");
  }
  json result = json::parse(response.text);
  return result;
}

float Weather::GetTemperature(const std::string& city) {
  json response = GetResponseForCity(city);
  return response["list"][0]["main"]["temp"];
}

cpr::Response Weather::Get(const std::string& city) {
  return cpr::Get(
      kBaseUrl, cpr::Parameters{
          {"q", city},
          {"appid", api_key_},
          {"units", "metric"}
      }
  );
}

std::string Weather::GetDifferenceString(const std::string &city1, const std::string &city2) {
  float diff = FindDiffBetweenTwoCities(city1, city2);
  std::stringstream output;
  output << "Weather in " << city1 << " ";
  if (diff < 0) {
    output << "is colder than in " << city2 << " by " << int(-diff) << " degrees";
  } else {
    output << "is warmer than in " << city2 << " by " << int(diff) << " degrees";
  }

  return output.str();
}

float Weather::FindDiffBetweenTwoCities(const std::string &city1, const std::string& city2) {
  return GetTemperature(city1) - GetTemperature(city2);
}
void Weather::SetApiKey(const std::string &api_key) {
  api_key_ = api_key;

}
