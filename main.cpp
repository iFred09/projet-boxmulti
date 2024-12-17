//
// main.cpp
// Created on 21/10/2018
//

#include "Base.h"
using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;

    Base *hello = new Base("hello", "hello.txt");
    hello->printValues(std::cout);
    std::cout << "Name: " << hello->getName() << std::endl;
    hello->setName("coucou");
    std::cout << "New Name: " << hello->getName() << std::endl;

    Base *boomboom = new Base("explosion", "boumboum.txt");
    boomboom->printValues(std::cout);
    boomboom->setName("boomboom");
    boomboom->setFileName("explosion.txt");
    boomboom->printValues(std::cout);
    return 0;
}
