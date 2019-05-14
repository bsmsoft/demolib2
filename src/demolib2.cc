#include <iostream>

#include "demolib1.h"
#include "demolib2.h"

void demo_lib2_print_fibonacci(int n) {
    std::cout << "Fibonacci " << n << ": " << demo_lib1_fibonacci(n) << std::endl;
}
