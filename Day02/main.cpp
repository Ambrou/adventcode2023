#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdint>


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

class Game
{
public:
    std::uint64_t numero{0};
    std::uint64_t maxRed{0};
    std::uint64_t maxBlue{0};
    std::uint64_t maxGreen{0};
};

unsigned long treatPartOne()
{
    std::vector<Game> games;
    std::string line;
    std::ifstream infile("input.txt");
    unsigned long result = 0;
    while (std::getline(infile, line))
    {
        Game game{};
        std::uint64_t iLoop{0};
        std::uint64_t startId{0};
        std::uint64_t endId{0};
        while(!isdigit(line[iLoop]))
        {
            iLoop++;
        }
        startId = iLoop;

        while(isdigit(line[iLoop]))
        {
            iLoop++;
        }
        endId = iLoop;
        const auto gameId{line.substr(startId, endId - startId)};
        game.numero = std::stoull(gameId);
        

        auto strBalls = line.substr(endId + 1);

        std::vector<std::string> sets;
        std::string parsed{};
        std::stringstream ss{strBalls};
        while (std::getline(ss, parsed,';'))
        {
            sets.push_back(parsed);
        }

        for(const auto set : sets)
        {
            std::stringstream sssets{set};

            std::vector<std::string> cubes;
            while (std::getline(sssets, parsed, ','))
            {
                cubes.push_back(parsed);
            }

            for(auto cube : cubes)
            {
                std::stringstream sscubes{cube};
                std::vector<std::string> balls;
                while (std::getline(sscubes, parsed, ' '))
                {
                    balls.push_back(parsed);
                }

                if(balls[2][0] == 'r')
                {
                    game.maxRed = std::max(game.maxRed, std::stoul(balls[1]));
                }
                else if(balls[2][0] == 'g')
                {
                    game.maxGreen = std::max(game.maxGreen, std::stoul(balls[1]));
                }
                else if(balls[2][0] == 'b')
                {
                    game.maxBlue = std::max(game.maxBlue, std::stoul(balls[1]));
                }
            }
        }
      
        games.push_back(game);
        
    };

    for(const auto& game : games)
    {
        if(game.maxRed < 13 && game.maxGreen < 14 && game.maxBlue < 15)
        {
            result += game.numero;
        }
    }
    return result;
}


unsigned long treatPartTwo()
{
    std::string line;
    std::ifstream infile("input.txt");
    unsigned long result = 0;
    while (std::getline(infile, line))
    {
       
        
    }
    return result;
}