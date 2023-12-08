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
void solve();

int main()
{
    std::cout << "Hello World" << std::endl;

    const std::vector<std::string> lines = parseInput();
    std::cout << "Resultat part 1 : " << treatPartOne(lines) << std::endl;
    //solve();


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
            if(isdigit(lines[i][j]))
            {
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
                    //std::cout << "tag at line " << i << " and column " << j << " with value " << lines[i][j] << std::endl;
                    std::string number{};
                    // Search statup number
                    while(j > 0 && isdigit(lines[i][j-1]))
                    {
                        j--;
                    };

                    do
                    {
                        if(isdigit(lines[i][j]))
                        {
                            number += lines[i][j];
                        }
                        j++;
                    }while(j != lines[i].size() && isdigit(lines[i][j]));

                    if(number.size() != 0)
                    {
                        //std::cout << number <<  " ";
                        result += std::stoul(number);
                    }
                    
                }
            }
        }
        //std::cout << std::endl;
    }
    return result;
}




void checkDown2(bool &tag, const std::vector<std::string>& lines, int& i, int& j, std::pair<int, int>& coord)
{
    if(!tag && i != lines.size()-1)
    {
        if(isdigit(lines[i+1][j]))
        {
            tag = true;
            coord.first = i+1;
            coord.second = j;
        }
    }
}

void checkUp2(bool &tag, const std::vector<std::string>& lines, int& i, int& j, std::pair<int, int>& coord)
{
    if(!tag && i != 0)
    {
        if(isdigit(lines[i-1][j]))
        {
            tag = true;
            coord.first = i-1;
            coord.second = j;
        }
    }
}

void checkLeft2(bool &tag, const std::vector<std::string>& lines, int& i, int& j, std::pair<int, int>& coord)
{
    if(!tag && j != 0)
    {
        if(isdigit(lines[i][j-1]))
        {
            tag = true;
            coord.first = i;
            coord.second = j-1;
        }
    }
}

void checkRight2(bool &tag, const std::vector<std::string>& lines, int& i, int& j, std::pair<int, int>& coord)
{
    if(!tag && j != lines[i].size() - 1)
    {
        if(isdigit(lines[i][j+1]))
        {
            tag = true;
            coord.first = i;
            coord.second = j+1;
        }
    }
}

void checkDownLeft2(bool &tag, const std::vector<std::string>& lines, int& i, int& j, std::pair<int, int>& coord)
{
    if(!tag && i != lines.size()-1 && j != 0)
    {
        if(isdigit(lines[i+1][j-1]))
        {
            tag = true;
            coord.first = i+1;
            coord.second = j-1;
        }
    }
}

void checkDownRight2(bool &tag, const std::vector<std::string>& lines, int& i, int& j, std::pair<int, int>& coord)
{
    if(!tag && i != lines.size()-1 && j != lines[i].size() - 1)
    {
        if(isdigit(lines[i+1][j+1]))
        {
            tag = true;
            coord.first = i+1;
            coord.second = j+1;
        }
    }
}

void checkUpLeft2(bool &tag, const std::vector<std::string>& lines, int& i, int& j, std::pair<int, int>& coord)
{
    if(!tag && i != 0 && j != 0)
    {
        if(isdigit(lines[i-1][j-1]))
        {
            tag = true;
            coord.first = i-1;
            coord.second = j-1;
        }
    }
}

void checkUpRight2(bool &tag, const std::vector<std::string>& lines, int& i, int& j, std::pair<int, int>& coord)
{
    if(!tag &&  i != 0 && j != lines[i].size() - 1)
    {
        if(isdigit(lines[i-1][j+1]))
        {
            tag = true;
            coord.first = i-1;
            coord.second = j+1;
        }
    }
}

unsigned long treatPartTwo(const std::vector<std::string>& lines)
{
    unsigned long result = 0;
    for(int i = 0; i < lines.size(); ++i)
    {
        for(int j = 0; j < lines[i].size(); ++j)
        {
            if(lines[i][j] == '*')
            {
                bool tag = false;
                bool firstFound;
                bool secondFound;
                std::string fisrtNumber{};
                std::string secondNumber{};
                std::pair<int, int> coord;
                coord.first = -1;
                coord.second = -1;
                // Search First Number (Sens horaire)
                checkUpLeft2(tag, lines, i, j, coord);
                checkUp2(tag, lines, i, j, coord);
                checkUpRight2(tag, lines, i, j, coord);
                checkRight2(tag, lines, i, j, coord);
                checkDownRight2(tag, lines, i, j, coord);
                checkDown2(tag, lines, i, j, coord);
                checkDownLeft2(tag, lines, i, j, coord);
                checkLeft2(tag, lines, i, j, coord);
                firstFound = tag;

                if(firstFound)
                {
                    //std::cout << "firstNumber found at " << coord.first << " " << coord.second << std::endl;
                    // Search statup number
                    while(coord.second > 0 && isdigit(lines[coord.first][coord.second-1]))
                    {
                        coord.second--;
                    };

                    do
                    {
                        if(isdigit(lines[coord.first][coord.second]))
                        {
                            fisrtNumber += lines[coord.first][coord.second];
                        }
                        coord.second++;
                    }while(coord.second != lines[coord.first].size() && isdigit(lines[coord.first][coord.second]));
                }

                tag = false;
                coord.first = -1;
                coord.second = -1;
                // Search Second Numbe (Sens anti-horaire)
                checkLeft2(tag, lines, i, j, coord);
                checkDownLeft2(tag, lines, i, j, coord);
                checkDown2(tag, lines, i, j, coord);
                checkDownRight2(tag, lines, i, j, coord);
                checkRight2(tag, lines, i, j, coord);
                checkUpRight2(tag, lines, i, j, coord);
                checkUp2(tag, lines, i, j, coord);
                checkUpLeft2(tag, lines, i, j, coord);
                secondFound = tag;

                

                if(secondFound)
                {
                    
                    // Search statup number
                    while(coord.second > 0 && isdigit(lines[coord.first][coord.second-1]))
                    {
                        coord.second--;
                    };

                    do
                    {
                        if(isdigit(lines[coord.first][coord.second]))
                        {
                            secondNumber += lines[coord.first][coord.second];
                        }
                        coord.second++;
                    }while(coord.second != lines[coord.first].size() && isdigit(lines[coord.first][coord.second]));
                }

                    //std::cout << fisrtNumber << " " << secondNumber << std::endl;
                tag = false;
                // If two numbers found and not at the startup
                if(secondFound && firstFound && secondNumber != fisrtNumber)
                {
                    
                    // multiplue them
                    auto mul = std::stoul(fisrtNumber) * std::stoul(secondNumber);
                    result += mul;
                    // add it to result
                }
            }
        }
    }
    return result;
}