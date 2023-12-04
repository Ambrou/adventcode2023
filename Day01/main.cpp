#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

int main()
{
    std::cout << "Hello World" << std::endl;

    std::string line;
    std::ifstream infile("input.txt");
    while (std::getline(infile, line))
    {
       std::cout << line << std::endl;
    }

    std::cout << "Bye World" << std::endl;

    return 0;
}
