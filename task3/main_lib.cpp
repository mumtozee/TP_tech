#include <buffer.h>

#include <iostream>

int main() {
    Buffer buffer;
    buffer.Set("Variable");
    std::cout << buffer.Get() << std::endl;
    return 0;
}
