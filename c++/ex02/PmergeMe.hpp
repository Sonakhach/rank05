#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
// #include <algorithm>
#include <vector>
#include <deque>
#include <time.h>

const int LIMIT = 5;

class PmergeMe
{
private:
    std::deque <int> m_deq;
    std::vector <int> m_vec;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe(const std::deque <int> &deq, const std::vector <int> &vec);
    PmergeMe &operator=(const PmergeMe &obj);
public:
    void print_map_deq();
    void print_map_vec();
    void insertionSort(std::deque <int> &m_deq, int n);
    void insertionSort(std::vector <int> &m_vec, int n);
    void	mergeInsertionSort(std::vector <int> &m_vec, int start, int end);
    void	mergeInsertionSort(std::deque <int> &m_deq, int start, int end);
    void MergeSortedIntervals(std::vector<int>& m_vec, int start, int mid, int end);
    void MergeSortedIntervals(std::deque<int>& m_deq, int start, int mid, int end); 
};



#endif
