#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            BitcoinExchange kk;
            kk.readDB();
            kk.readInputFile(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    else
        std::cout<< "ERROR: use program name and input.txt"<< std::endl;
}