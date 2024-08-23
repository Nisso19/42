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

		std::list<int> *_toSortList;
		std::list<int> *_sortedList;
        void _fillContainer(int* array, int array_size);
        void printContainer(void);
        void SortVector();
};

#endif