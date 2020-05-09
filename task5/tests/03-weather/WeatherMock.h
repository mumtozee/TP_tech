#ifndef WEATHER_MOCK_H
#define WEATHER_MOCK_H

#include <gmock/gmock.h>
#include "Weather.h"

class WeatherMock : public Weather {
public:
    MOCK_METHOD(cpr::Response, Get, (const std::string& city), (override));
};

#endif // WEATHER_MOCK_H
