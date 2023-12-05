#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>


unsigned long treatPartOne();
unsigned long treatPartTwo();

int main()
{
    std::cout << "Hello World" << std::endl;

    std::cout << "Resultat part 1 : " << treatPartOne() << std::endl;
    std::cout << "Resultat part 2 : " << treatPartTwo() << std::endl;

    std::cout << "Bye World" << std::endl;

    return 0;
}

unsigned long treatPartOne()
{
    std::string line;

    const auto isDigit = [](char c){return isdigit(c);};
    const auto toNumber = [](char c){return c - 0x30;};
    
    std::ifstream infile("input_part1.txt");
    unsigned long result = 0;
    while (std::getline(infile, line))
    {
        const auto firstCharNumber = std::find_if(begin(line), end(line), isDigit);

        // find last number
        const auto lastCharNumber = std::find_if(rbegin(line), rend(line), isDigit);
        
        // add them
        const auto firstNumber = toNumber(*firstCharNumber);
        const auto lastNumber = toNumber(*lastCharNumber);
        
        result += (firstNumber * 10) + lastNumber;
    }
    return result;
}


unsigned long treatPartTwo()
{
    std::string line;

    std::map<std::string, std::size_t> numbers = {{"0", -1}, {"1", -1}, {"2", -1}, {"3", -1}, {"4", -1}, {"5", -1}, {"6", -1}, {"7", -1}, {"8", -1}, {"9", -1}, {"one", -1}, {"two", -1}, {"three", -1}, {"four", -1}, {"five", -1}, {"six", -1}, {"seven", -1}, {"eight", -1}, {"nine", -1}};
    std::map<std::string, std::size_t> rnumbers = {{"0", 0}, {"1", 0}, {"2", 0}, {"3", 0}, {"4", 0}, {"5", 0}, {"6", 0}, {"7", 0}, {"8", 0}, {"9", 0}, {"one", 0}, {"two", 0}, {"three", 0}, {"four", 0}, {"five", 0}, {"six", 0}, {"seven", 0}, {"eight", 0}, {"nine", 0}};
    const auto isDigit = [](char c){return isdigit(c);};
    const auto toNumber = [](char c){return c - 0x30;};
    
    std::ifstream infile("input_part1.txt");
    unsigned long result = 0;
    while (std::getline(infile, line))
    {
        std::pair<std::string, std::size_t> firstNumber = {"no", 65536};

        
        std::cout << line << std::endl;
        // search first digit or number
        for(auto& number : numbers)
        {
            number.second = line.find(number.first);
            if(number.second < firstNumber.second)
            {
                firstNumber.second = number.second;
                firstNumber.first = number.first;
            }

        }
        std::pair<std::string, std::size_t> lastNumber = {"yes", 0};
        // search first digit or number
        for(auto& number : rnumbers)
        {
            number.second = line.rfind(number.first);
            if(number.second != std::string::npos)
            {
                if(number.second > lastNumber.second)
                {
                    lastNumber.second = number.second;
                    lastNumber.first = number.first;
                }
            }
            

        }
        std::cout << "First number " <<  firstNumber.first << std::endl;
        std::cout << "Last number  " <<  lastNumber.first << std::endl;
        // std::size_t firstPosition = 65535;
        // std::for_each(std::cbegin(numbers), std::cend(numbers), [&firstPosition, &line](std::string number){ firstPosition = std::min(firstPosition, line.find(number));});
        // const auto firstCharNumber = std::find_if(begin(line), end(line), isDigit);

        // // find last number
        // const auto lastCharNumber = std::find_if(rbegin(line), rend(line), isDigit);
        
        // // add them
        // const auto firstNumber = toNumber(*firstCharNumber);
        // const auto lastNumber = toNumber(*lastCharNumber);
        
        // result += (firstNumber * 10) + lastNumber;
    }
    return result;
}