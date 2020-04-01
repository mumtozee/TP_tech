#include <buffer.h>

void Buffer::Set(const std::string& string) {
    string_ = string;
}

std::string Buffer::Get() const {
    return string_;
}
