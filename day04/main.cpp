#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdint>
#include <memory>


class Numbers
{
public:
    void add(std::string number)
    {
        numbers.push_back(std::stoul(number));
    }
    void add(std::uint64_t number)
    {
        numbers.push_back(number);
    }
    bool empty() const
    {
        return numbers.size() == 0;
    }
    
    std::size_t size() const
    {
        return numbers.size();
    }
    std::vector<std::uint64_t> numbers{};
};

using WinningNumber = Numbers;
using YouHaveNumber = Numbers;

class Card
{
public:
    std::uint64_t numero{};
    WinningNumber winningNumber{};
    YouHaveNumber youHaveNumber{};
};

using Cards = std::vector<Card>;


Cards parseInput();

class Resolving
{
public:

    virtual std::uint64_t resolve(const Cards& cards) = 0;
};

class PartOneResolver : public Resolving
{
public:
    std::uint64_t resolve(const Cards& cards) override
    {
        std::uint64_t result{};
        std::for_each(std::cbegin(cards), std::cend(cards), [&result](const auto& card)
        {
            const auto& youHaveNumbers = card.youHaveNumber.numbers;
            Numbers numbers;
            std::for_each(std::cbegin(card.winningNumber.numbers), std::cend(card.winningNumber.numbers), [&youHaveNumbers, &numbers](const auto& number )
            {
                if(std::find(std::cbegin(youHaveNumbers), std::cend(youHaveNumbers), number) != std::cend(youHaveNumbers))
                {
                    //std:: cout << number << " ";
                    numbers.add(number);
                }
            });

            auto cardValues = numbers.empty() ? 0 : 1;

            for(std::size_t i = 1; i < numbers.size(); ++i)
            {
                cardValues *= 2;
            }
            //std::cout << cardValues << std::endl;
            result += cardValues;
        });
        return result;
    }

    private:
   
};

class PartTwoResolver : public Resolving
{
public:
    std::uint64_t resolve(const Cards& cards) override
    {
        std::uint64_t result{};
        return result;
    }
};

class Parser
{
public:
    Cards parse()
    {
        Cards cards;
        std::string line;
        std::ifstream infile("input.txt");
        while (std::getline(infile, line))
        {
            std::uint64_t index{};
            Card card;
            card.numero = extractCardNumero(index, line);


            while(!isdigit(line[index]) && index < line.size())
            {
                index++;
            }
            std::string number{};
            while(line[index] != '|' && index < line.size())
            {
                if(isdigit(line[index]))
                {
                    number += line[index];
                }
                else if(line[index] == ' ')
                {
                    if(!number.empty())
                    {
                        card.winningNumber.add(number);
                        number = std::string{};
                    }
                }
                index++;
            }

            while(!isdigit(line[index]) && index < line.size())
            {
                index++;
            }

            while(index < line.size())
            {
                if(isdigit(line[index]))
                {
                    number += line[index];
                }
                else if(line[index] == ' ')
                {
                    if(!number.empty())
                    {
                        card.youHaveNumber.add(number);
                        number = std::string{};
                    }

                }
                index++;
            }

            if(!number.empty())
            {
                card.youHaveNumber.add(number);
                number = std::string{};
            }
            
            //std::cout << card.numero << " ";
            std::for_each(std::cbegin(card.winningNumber.numbers), std::cend(card.winningNumber.numbers), [](std::uint64_t number)
            {
                //std::cout << number << " ";
            });

            //std::cout << " | ";
            std::for_each(std::cbegin(card.youHaveNumber.numbers), std::cend(card.youHaveNumber.numbers), [](std::uint64_t number)
            {
                //std::cout << number << " ";
            });


            //std::cout << std::endl;
            cards.push_back(card);
        }
        
        return cards;
    }


    private:
    std::uint64_t extractCardNumero(std::uint64_t& index, const std::string& line)
    {
        while(!isdigit(line[index]) && index < line.size())
        {
            index++;
        }
        std::string cardNumero{};
        while(isdigit(line[index]) && index < line.size())
        {
            cardNumero += line[index];
            index++;
        }
        return std::stoul(cardNumero);
    }
};

int main()
{
    std::cout << "Hello World" << std::endl;

    Parser parser{};
    const Cards cards = parser.parse();
    

    std::unique_ptr<Resolving> resolver = std::make_unique<PartOneResolver>();
    std::cout << "Resultat part 1 : " << resolver->resolve(cards) << std::endl;
    resolver = std::make_unique<PartTwoResolver>();
    std::cout << "Resultat part 2 : " << resolver->resolve(cards) << std::endl;

    std::cout << "Bye World" << std::endl;

    return 0;

}
