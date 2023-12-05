#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdint>


unsigned long treatPartOne(const std::vector<std::string>& lines);
unsigned long treatPartTwo(const std::vector<std::string>& lines);
std::vector<std::string> parseInput();

int main()
{
    std::cout << "Hello World" << std::endl;

    const std::vector<std::string> lines = parseInput();
    std::cout << "Resultat part 1 : " << treatPartOne(lines) << std::endl;
    std::cout << "Resultat part 2 : " << treatPartTwo(lines) << std::endl;

    std::cout << "Bye World" << std::endl;

    return 0;

}

std::vector<std::string> parseInput()
{
    std::vector<std::string> lines;
    std::string line;
    std::ifstream infile("input.txt");
    while (std::getline(infile, line))
    {
        lines.push_back(line);
    }
    return lines;
}

void checkDown(bool &tag, const std::vector<std::string>& lines, int& i, int& j)
{
    if(!tag && i != lines.size()-1)
    {
        if(lines[i+1][j] != '.' && !isdigit(lines[i+1][j]))
        {
            tag = true;
        }
    }
}

void checkUp(bool &tag, const std::vector<std::string>& lines, int& i, int& j)
{
    if(!tag && i != 0)
    {
        if(lines[i-1][j] != '.' && !isdigit(lines[i-1][j]))
        {
            tag = true;
        }
    }
}

void checkLeft(bool &tag, const std::vector<std::string>& lines, int& i, int& j)
{
    if(!tag && j != 0)
    {
        if(lines[i][j-1] != '.' && !isdigit(lines[i][j-1]))
        {
            tag = true;
        }
    }
}

void checkRight(bool &tag, const std::vector<std::string>& lines, int& i, int& j)
{
    if(!tag && j != lines[i].size() - 1)
    {
        if(lines[i][j+1] != '.' && !isdigit(lines[i][j+1]))
        {
            tag = true;
        }
    }
}

void checkDownLeft(bool &tag, const std::vector<std::string>& lines, int& i, int& j)
{
    if(!tag && i != lines.size()-1 && j != 0)
    {
        if(lines[i+1][j-1] != '.' && !isdigit(lines[i+1][j-1]))
        {
            tag = true;
        }
    }
}

void checkDownRight(bool &tag, const std::vector<std::string>& lines, int& i, int& j)
{
    if(!tag && i != lines.size()-1 && j != lines[i].size() - 1)
    {
        if(lines[i+1][j+1] != '.' && !isdigit(lines[i+1][j+1]))
        {
            tag = true;
        }
    }
}

void checkUpLeft(bool &tag, const std::vector<std::string>& lines, int& i, int& j)
{
    if(!tag && i != 0 && j != 0)
    {
        if(lines[i-1][j-1] != '.' && !isdigit(lines[i-1][j-1]))
        {
            tag = true;
        }
    }
}

void checkUpRight(bool &tag, const std::vector<std::string>& lines, int& i, int& j)
{
    if(!tag &&  i != 0 && j != lines[i].size() - 1)
    {
        if(lines[i-1][j+1] != '.' && !isdigit(lines[i-1][j+1]))
        {
            tag = true;
        }
    }
}

unsigned long treatPartOne(const std::vector<std::string>& lines)
{
    unsigned long result = 0;
    for(int i = 0; i < lines.size(); ++i)
    {
        for(int j = 0; j < lines[i].size(); ++j)
        {
            //std::cout << lines[i][j];
            bool tag = false;
            checkDown(tag, lines, i, j);
            checkUp(tag, lines, i, j);
            checkLeft(tag, lines, i, j);
            checkRight(tag, lines, i, j);
            checkUpRight(tag, lines, i, j);
            checkDownRight(tag, lines, i, j);
            checkUpLeft(tag, lines, i, j);
            checkDownLeft(tag, lines, i, j);
            if(tag)
            {
                std::string number{};
                // if(isdigit(lines[i][j]))
                // {
                //     number += lines[i][j];
                // }
                // j++;
                // while(isdigit(lines[i][j]))
                // {
                //     number += lines[i][j];
                //     j++;
                //     if(j == lines[i].size())
                //     {
                //         break;
                //     }
                // };

                // while(j < lines[i].size() - 1)
                // {
                //     if(isdigit(lines[i][j]))
                //     {
                //         number += lines[i][j];
                //     }
                //     j++;
                //     if(!isdigit(lines[i][j]))
                //     {
                //         break;
                //     }
                // };
                
                std::cout << number << std::endl;
            }
        }
        //std::cout << std::endl;
    }
    return result;
}
unsigned long treatPartTwo(const std::vector<std::string>& lines)
{
    return 0;
}