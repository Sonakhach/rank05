#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
BitcoinExchange:: BitcoinExchange(const BitcoinExchange &obj)
{
    *this = obj;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
        ratesMap = obj.ratesMap;
    return(*this);

}
void BitcoinExchange::readDB()
{
    std::ifstream fin("data.csv");
    std::string line;
    std::string delimiter = ",";
    std::string token;
    double          price;
    size_t pos = 0;
    if (fin.fail())
    {
        throw std::runtime_error("can't open file");
    }
    if (!getline(fin, line))
    {
        throw std::runtime_error("input file is empty");
    }
    while (!fin.eof())
    {
        getline(fin,line);
        while ((pos = line.find(delimiter))!= std::string::npos)
        {
            token = line.substr(0,pos);
            price = std::strtod(line.erase(0,pos+delimiter.length()).c_str(), NULL);
            ratesMap[token] = price;
        }
    }
    
    fin.close();
}

// void BitcoinExchange::print_map()
// {
//     for(Map::iterator it = ratesMap.begin(); it != ratesMap.end(); ++it)
//     {
//         std::cout << "{" << it->first << ": " << it->second << "}\n";
//     }
// }

 void BitcoinExchange::readInputFile(std::string inputFile)
 {
    std::ifstream file(inputFile.c_str());
    std::string line;
    std::string delimiter = "|";
    std::string token;
    double          price;
    size_t pos = 0;
    if (file.fail())
    {
       throw std::runtime_error("can't open file");
    }
    if (!getline(file, line))
    {
        throw std::runtime_error("input file is empty");
    }
    if (line != "date | value")
    {
        throw std::runtime_error("incorrect header line");
    }
    while (!file.eof())
    {
        getline(file,line);
        if ((line.find(delimiter) == std::string::npos))
        {
            std::string str = line.c_str();
            if (str[0] == '\0')
            {
                continue;
            }
            else
                std::cout<<"Error: bad input"<< " => "<<line <<std::endl;
        }
        while ((pos = line.find(delimiter))!= std::string::npos)
        {
            char *endPtr;
            token = line.substr(0,pos);
            price = std::strtod(line.erase(0,pos+delimiter.length()).c_str(), &endPtr);
            if (price > 1000)
            {
                std::cout<<"Error: too large a number"<<std::endl;
                break;
            }
            else if (price < 0)
            {
                std::cout<<"Error: not a positive number"<<std::endl;
                break;
            }
            
            if (!validData(token))
            {
                std::cout << "Error: bad input" << " => "<< token << std::endl;
                break;
            }
            token.erase(token.length() - 1);
            Map::iterator it = ratesMap.lower_bound(token);
            if (it != ratesMap.end())
            {
                std::cout << token << " => " << price << " = " << price * (it->second) << std::endl;   
            }
            else
            {
                 std::cout << "Error: not found" << " => "<< token << std::endl;
                break;
            // throw std::runtime_error("not found data for change");
            }
        }
    }
    file.close();
 }

bool BitcoinExchange::validData(std::string token)
{

    int year ;
    int month ;
    int day ;
    std::stringstream valY;
    std::stringstream valM;
    std::stringstream valD;
        if (token[4] == '-' && token[7] == '-' )
        {
            valY << token.substr(0, 4);
            valY >> year;
            if (year<= 0)
                return false;
            valM << token.substr(5, 2);
            valM >> month;
            if (month < 1 || month > 12)
            {
                return false;
            }
            valD << token.substr(8);
            valD >> day;
            switch (day)
            {
                case 4: case 6: case 9: case 11:
                    return (day <= 30);
                case 2:
                    return (day <= 29);
                default:
                    return (day <= 31);
            }
            if (day < 1 || day > 31)
               return false;
        }
        else
        {
            return false;
        }
   return true;
}