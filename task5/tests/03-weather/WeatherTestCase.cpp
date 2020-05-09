#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;


TEST(WeatherTestCase, WrongCity) {
    cpr::Response custom_response;
    custom_response.status_code = 450;
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get("bulgugu"))
    .Times(1)
    .WillOnce(Return(custom_response));

    ASSERT_THROW(wm.GetResponseForCity("bulgugu"), std::invalid_argument);
}

TEST(WeatherTestCase, GetResponseForCity) {
    std::string city_name = "London";
    cpr::Response custom_response;
    custom_response.status_code = 200;
    custom_response.text = "{\"name\" : \"Martin\"}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city_name))
    .Times(1)
    .WillOnce(Return(custom_response));

    json result = wm.GetResponseForCity(city_name);
    ASSERT_EQ(result["name"], "Martin");
}

TEST(WeatherTestCase, GetTemperature) {
    std::string city_name = "London";
    cpr::Response custom_response;
    custom_response.status_code = 200;
    custom_response.text = "{\"list\" : [{\"main\" : {\"temp\" : 45.0}}]}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city_name))
    .Times(1)
    .WillOnce(Return(custom_response));

    float result = wm.GetTemperature(city_name);
    ASSERT_EQ(result, 45.0);
}

TEST(WeatherTestCase, FindDiffBetweenTwoCities) {
    std::string city1_name = "London";
    cpr::Response custom_response1;
    custom_response1.status_code = 200;
    custom_response1.text = "{\"list\" : [{\"main\" : {\"temp\" : 45.0}}]}";

    std::string city2_name = "Zurich";
    cpr::Response custom_response2;
    custom_response2.status_code = 200;
    custom_response2.text = "{\"list\" : [{\"main\" : {\"temp\" : 27.5}}]}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city1_name))
    .Times(1)
    .WillOnce(Return(custom_response1));

    EXPECT_CALL(wm, Get(city2_name))
    .Times(1)
    .WillOnce(Return(custom_response2));

    float result = wm.FindDiffBetweenTwoCities(city1_name, city2_name);
    ASSERT_EQ(result, 17.5);
}

TEST(WeatherTestCase, GetDifferenceString) {
    std::string city1_name = "London";
    cpr::Response custom_response1;
    custom_response1.status_code = 200;
    custom_response1.text = "{\"list\" : [{\"main\" : {\"temp\" : 45.0}}]}";

    std::string city2_name = "Zurich";
    cpr::Response custom_response2;
    custom_response2.status_code = 200;
    custom_response2.text = "{\"list\" : [{\"main\" : {\"temp\" : 27.5}}]}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city1_name))
    .Times(1)
    .WillOnce(Return(custom_response1));

    EXPECT_CALL(wm, Get(city2_name))
    .Times(1)
    .WillOnce(Return(custom_response2));

    std::string result = wm.GetDifferenceString(city1_name, city2_name);
    std::string verdict = "Weather in London is warmer than in Zurich by 17 degrees";
    ASSERT_EQ(result, verdict);
}

TEST(WeatherTestCase, GetDifferenceString2) {
    std::string city1_name = "London";
    cpr::Response custom_response1;
    custom_response1.status_code = 200;
    custom_response1.text = "{\"list\" : [{\"main\" : {\"temp\" : 45.0}}]}";

    std::string city2_name = "Zurich";
    cpr::Response custom_response2;
    custom_response2.status_code = 200;
    custom_response2.text = "{\"list\" : [{\"main\" : {\"temp\" : 27.5}}]}";
    WeatherMock wm;
    
    EXPECT_CALL(wm, Get(city1_name))
    .Times(1)
    .WillOnce(Return(custom_response1));

    EXPECT_CALL(wm, Get(city2_name))
    .Times(1)
    .WillOnce(Return(custom_response2));

    std::string result = wm.GetDifferenceString(city2_name, city1_name);
    std::string verdict = "Weather in Zurich is colder than in London by 17 degrees";
    ASSERT_EQ(result, verdict);
}


TEST(WeatherTestCase, SetApiKey) {
    WeatherMock wm;
    ASSERT_NO_THROW(wm.SetApiKey("some key"));
}

