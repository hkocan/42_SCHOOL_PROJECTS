#include <iostream>
#include <cstdlib>

int main()
{

    srand(time(0)); // Seed the random number generator
    std::cout << rand() << std::endl;
    std::cout << rand() << std::endl;
    std::cout << rand() << std::endl;
}