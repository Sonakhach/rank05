#include "PmergeMe.hpp"

void checkDigit(char **str)
{
    int i = 1; 
    while(str[i])
    {
        int j = 0;
        while(str[i][j])
        {
            if(!isdigit(str[i][j]))
            {
                throw std::invalid_argument("Bad input");
            }            
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
   
    if (ac > 2)
    {
        try
        {
            std::deque <int> deq;
            std::vector<int>vec;
            for (int i = 1; i < ac; i++)
            {
                checkDigit(av);
                int a = atoi(av[i]);
                if(a < 0)
                {
                     throw std::invalid_argument("error");
                }
                deq.push_back(a); 
                vec.push_back(a);
            }
            PmergeMe obj( deq, vec);
            obj.print_map_deq();
            clock_t start_time = clock();
            obj.mergeInsertionSort(deq, 0, ac - 1);
            clock_t end_time = clock();
            double  deque_time = static_cast<double>(end_time - start_time) / 10000;
            std::cout << "Deque After  ";
            for(std::deque <int>::iterator it = deq.begin(); it != deq.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << '\n';
            obj.print_map_vec();
            clock_t start_time_vec = clock();
            obj.mergeInsertionSort(vec, 0, ac - 1);
            clock_t end_time_vec = clock();
            double  vector_time = static_cast<double>(end_time_vec - start_time_vec) / 10000;
            std::cout << "Vector After  ";
            for(std::vector <int>::iterator it = vec.begin(); it != vec.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << '\n';
            std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deque_time  << " us" << std::endl;
            std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vector_time  << " us" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout<< "ERROR: use program name "<< std::endl;
}