#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <sstream>

typedef std::map<std::string, float , std::greater <std::string> > Map;

class BitcoinExchange
{
private:
   Map ratesMap;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    ~BitcoinExchange();
    void readDB();
    // void print_map();
    void readInputFile(std::string inputFile);
    bool validData(std::string token);
};

#endif
