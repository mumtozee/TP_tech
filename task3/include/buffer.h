#pragma once

#include <string>
class Buffer {
 public:
    void Set(const std::string& string);
    std::string Get() const;
 private:
    std::string string_;
};
