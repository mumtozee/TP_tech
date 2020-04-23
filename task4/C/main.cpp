#include "main.h"
#include <iostream>

int main() {

    ClassLib class_;
    class_.Set(1);

    std::cout << class_.Get() << std::endl;
    return 0;
}
