#include <iostream>

#include "demolib1.h"
#include "demolib2.h"

void demo_lib2_print_factorial(int n) {
    std::cout << "Factorial " << n << ": " << demo_lib1_factorial(n) << std::endl;
}
