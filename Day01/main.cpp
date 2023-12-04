#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    std::cout << "Hello World" << std::endl;

    std::string line;
    std::ifstream infile("input_part1.txt");
    unsigned long result = 0;
    while (std::getline(infile, line))
    {
        const auto firstCharNumber = std::find_if(begin(line), end(line), [](char c)
        {
            return isdigit(c);
        });

       // find last number
       const auto lastCharNumber = std::find_if(rbegin(line), rend(line), [](char c)
        {
            return isdigit(c);
        });

        
       // add them
       const auto firstNumber = *firstCharNumber - 0x30;
       const auto lastNumber = *lastCharNumber - 0x30;
        
        result += (firstNumber * 10) + lastNumber;
    }

    std::cout << "Resultat part 1 : " << result << std::endl;

    std::cout << "Bye World" << std::endl;

    return 0;
}
