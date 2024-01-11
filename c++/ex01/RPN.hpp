#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>


class RPN
{
private:
    std::stack <int> m_stack; 
public:
    RPN();
    RPN (const std::string &str);
    ~RPN();
    RPN(const RPN &obj);
    RPN &operator=(const RPN &obj);
public:
    void oper(std::string str);
    //  void RPN::print_map();
};


#endif