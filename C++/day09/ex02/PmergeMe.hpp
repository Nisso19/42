#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstddef>
#include <exception>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <errno.h>

class PmergeMe
{
    private:

        bool _container;
        int _straggler;

    public:
        PmergeMe( int* array, int array_size, bool container );
        PmergeMe(PmergeMe const & ToCopy);
        PmergeMe& operator=(PmergeMe const & ToAffect);
        ~PmergeMe(void);

        std::vector<std::pair<int, int> >  *_toSortVector;
		std::vector<int> *_sortedVector;

		std::list<std::pair<int, int> > *_toSortList;
		std::list<int> *_sortedList;
        void _fillVectorContainer(int* array, int array_size);
        void _fillListContainer(int* array, int array_size);
        void printContainer(void);
        //void SortVector();
        void merge(std::list<std::pair<int, int> >& clist, int begin, int mid, int end);
        void merge(std::vector<std::pair<int, int> >& vector, int begin, int mid, int end);
        template <typename T>
        void sort(T& container, int begin, int end); 
};

#endif