#include "PmergeMe.hpp"

PmergeMe::PmergeMe():  m_deq(0) , m_vec(0) 
{
    
}

PmergeMe::PmergeMe(const std::deque <int> &deq, const std::vector <int> &vec):  m_deq(deq) , m_vec(vec) 
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    m_deq = obj.m_deq;
    m_vec = obj.m_vec;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if(this != &obj)
    {
        m_deq = obj.m_deq;
        m_vec = obj.m_vec;
    }
    return (*this);
}
void PmergeMe::print_map_deq()
{
    std::cout << "Deque Before  ";
    for(std::deque <int>::iterator it = m_deq.begin(); it != m_deq.end(); ++it)
    {
        std::cout << *it << " " ;
    }
    std::cout << '\n';
}

void PmergeMe::print_map_vec()
{
     std::cout << "Vector Befor  ";
    for(std::vector <int>::iterator it = m_vec.begin(); it != m_vec.end(); ++it)
    {
        std::cout << *it << " " ;
    }
    std::cout << '\n';
}

void PmergeMe::insertionSort(std::deque <int> &m_deq, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = m_deq[i];
        j = i - 1;
        while (j >= 0 && m_deq[j] > key) {
            m_deq[j + 1] = m_deq[j];
            j = j - 1;
        }
        m_deq[j + 1] = key;
    }
}


void PmergeMe::insertionSort(std::vector <int> &m_vec, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = m_vec[i];
        j = i - 1;
        while (j >= 0 && m_vec[j] > key) {
            m_vec[j + 1] = m_vec[j];
            j = j - 1;
        }
        m_vec[j + 1] = key;
    }
}

void	PmergeMe::mergeInsertionSort(std::vector <int> &m_vec, int start, int end)
{
	if (end - start <= LIMIT)
	{
        insertionSort(m_vec, end);
	}
	else
	{
        int mid = start + (end - start) / 2;
        mergeInsertionSort(m_vec, start, mid);
        mergeInsertionSort(m_vec, mid + 1, end);
        MergeSortedIntervals(m_vec, start, mid, end);
	}
}

void	PmergeMe::mergeInsertionSort(std::deque <int> &m_deq, int start, int end)
{
	if (end - start <= LIMIT)
	{
        insertionSort(m_deq, end);
	}
	else
	{
        int mid = start + (end - start) / 2;
        mergeInsertionSort(m_deq, start, mid);
        mergeInsertionSort(m_deq, mid + 1, end);
        MergeSortedIntervals(m_deq, start, mid, end);
	}
}

 
void PmergeMe::MergeSortedIntervals(std::vector<int>& m_vec, int start, int mid, int end) 
{    
	std::vector<int> temp;
	int i, j;
	i = start;
	j = mid + 1;
	while (i <= mid && j <= end) 
    {
		if (m_vec[i] <= m_vec[j]) {
			temp.push_back(m_vec[i]);
			++i;
		}
		else {
			temp.push_back(m_vec[j]);
			++j;
		}
	}
	while (i <= mid) {
		temp.push_back(m_vec[i]);
		++i;
	}
	while (j <= end) {
		temp.push_back(m_vec[j]);
		++j;
	}
	for (int i = start; i <= end; ++i)
		m_vec[i] = temp[i - start]; 
}

void PmergeMe::MergeSortedIntervals(std::deque<int>& m_deq, int start, int mid, int end) 
{
	 std::vector<int> temp;
	int i, j;
	i = start;
	j = mid + 1;
	while (i <= mid && j <= end) 
    {
		if (m_deq[i] <= m_deq[j]) {
			temp.push_back(m_deq[i]);
			++i;
		}
		else {
			temp.push_back(m_deq[j]);
			++j;
		}
	}
	while (i <= mid) {
		temp.push_back(m_deq[i]);
		++i;
	}
	while (j <= end) {
		temp.push_back(m_deq[j]);
		++j;
	}
	for (int i = start; i <= end; ++i)
		m_deq[i] = temp[i - start]; 
} 


