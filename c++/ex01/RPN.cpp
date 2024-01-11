#include "RPN.hpp"

RPN::RPN()
{ 
}
RPN::RPN(const std::string &str)
{
    for(size_t i = 0; i < str.size() - 2; i++)
    {
        if ((isdigit(str[i])  || str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ) && 
        (str[i + 1] == ' ' || isdigit(str[i + 1]) || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/'))
            continue;
        else
            throw std::invalid_argument("error1");
    }
    if (str[str.size() - 1] != '+' && str[str.size() - 1] != '-' && str[str.size() - 1] != '*' && str[str.size() - 1] != '/')
        throw std::invalid_argument("error2");
   
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &obj)
{
    m_stack = obj.m_stack;
}

RPN &RPN::operator=(const RPN &obj)
{
    if (this != &obj)
        m_stack = obj.m_stack;
return (*this);
}

void RPN::oper(std::string str)
{
    
    int num1 = 0;
    int num2 = 0;
    for(size_t i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            m_stack.push(str[i] - '0');            
        if (str[i] != ' ' && !isdigit(str[i]))
        {
            if (m_stack.size() < 2)
                throw std::invalid_argument("ERROR");
            
            num1 = m_stack.top();
            m_stack.pop();
            num2 = m_stack.top();
            m_stack.pop();
        } 
        if (str[i] == '+')
            m_stack.push(num2 + num1);
        else if (str[i] == '-')  
            m_stack.push(num2 - num1);
        else if (str[i] == '*')  
            m_stack.push(num2 * num1);
        else if (str[i] == '/')  
            m_stack.push(num2 / num1);
    }
    // void print_map()
    // {
    //     int i = 0;
    //     for(Map::iterator it = m_stack.begin(); it != m_stack.end() - 1 ; ++it)
    //     {
    //         i ++;
    //         std::cout << "{"  "}\n";
    //     }
    //     std::cout << i <<std::endl;
    // }
    std::cout << m_stack.top() << std::endl;
}