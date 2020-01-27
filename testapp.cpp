#include "tested_class.h"
#include <iostream>

int main(int argc, char ** argv)
{
    TestClass test;
    std::cout << "1+5=" << test.add(1,5);

    return 0;
}