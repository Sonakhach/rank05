#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            std::string a = av[1]; 
            RPN obj(a);
            obj.oper(a);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout<< "ERROR: use program name and input.txt"<< std::endl;
}