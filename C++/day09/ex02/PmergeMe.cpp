#include "PmergeMe.hpp"

PmergeMe::PmergeMe( int* array, int array_size, bool container ) : _container( container )
{
	_toSortVector = new std::vector<std::pair<int, int> >;
	_sortedVector = new std::vector<int>();
	_toSortList = new std::list<std::pair<int, int> >;
	_sortedList = new std::list<int>();

    // (void)array;
    // (void)array_size;
    // (void)container;
	if (array_size % 2)
	{
		_straggler = array[array_size - 1];
		array[array_size - 1 ] = 0;
	}
	if ( container == 0 )
	{
		_fillVectorContainer(array, array_size);
	}
	else if ( container == 1 )
	{
		_fillListContainer(array, array_size);
	}
}

void PmergeMe::_fillVectorContainer(int* array, int array_size)
{
	int i;
	int a;
	int b;
	for (i = 0; i + 1 < array_size; i += 2)
	{
		a = array[i];
		b = array[i + 1];
		if (a < b)
			_toSortVector->push_back(std::pair<int, int>(b, a));
		else
			_toSortVector->push_back(std::pair<int, int>(a, b));
	}
	sort(*_toSortVector, 0, _toSortVector->size() - 1);
}

void PmergeMe::_fillListContainer(int* array, int array_size)
{
	int i;
	int a;
	int b;
	for (i = 0; i + 1 < array_size; i += 2)
	{
		a = array[i];
		b = array[i + 1];
		if (a < b)
			_toSortList->push_back(std::pair<int, int>(b, a));
		else
			_toSortList->push_back(std::pair<int, int>(a, b));
	}
	sort(*_toSortList, 0, _toSortList->size() - 1);
}

void PmergeMe::merge(std::list<std::pair<int, int> >& list, int begin, int mid, int end)
{
	int RlistIndex= 0;
    int LlistIndex = 0;
    int sizeLlist = mid - begin + 1;
	int sizeRlist = end - mid;
	std::list<std::pair<int, int> >::iterator ListBegin = list.begin();
	std::list<std::pair<int, int> >::iterator ListEnd = list.begin();
	std::advance(ListBegin, begin);
	std::advance(ListEnd, mid + 1);
	std::list<std::pair<int, int> > Llist(ListBegin, ListEnd);
	ListBegin = list.begin();
	ListEnd = list.begin();
	std::advance(ListBegin, begin + mid + 1);
	std::advance(ListEnd, end + 1);
	std::list<std::pair<int, int> > Rlist(ListBegin, ListEnd);

	for (int i = begin; i < end + 1; ++i)
	{
		std::list<std::pair<int, int> >::iterator itList = list.begin();
		std::list<std::pair<int, int> >::iterator itRlist = Rlist.begin();
		std::list<std::pair<int, int> >::iterator itLlist = Llist.begin();
		std::advance(itList, i);
		std::advance(itRlist, RlistIndex);
		std::advance(itLlist, LlistIndex);
        if (RlistIndex == sizeRlist) 
		{
            *itList = *itLlist;
            LlistIndex++;
        } 
		else if (LlistIndex == sizeLlist) 
		{
            *itList = *itRlist;
            RlistIndex++;
        } 
		else if (*itRlist > *itLlist)
		{
            *itList = *itLlist;
            LlistIndex++;
        } 
		else 
		{
            *itList = *itRlist;
            RlistIndex++;
        }
    }	
}

void PmergeMe::merge(std::vector<std::pair<int, int> >& vector, int begin, int mid, int end)
{
	int RvecIndex= 0;
    int LvecIndex = 0;
    int sizeLvec = mid - begin + 1;
	int sizeRvec = end - mid;
	std::vector<std::pair<int, int> > Lvec((vector.begin() + begin), (vector.begin() + mid + 1));
	std::vector<std::pair<int, int> > Rvec((vector.begin() + mid + 1), (vector.begin() + end + 1));
	for (int i = begin; i < end + 1; ++i)
	{
        if (RvecIndex == sizeRvec) 
		{
            vector[i] = Lvec[LvecIndex];
            LvecIndex++;
        } 
		else if (LvecIndex == sizeLvec) 
		{
            vector[i] = Rvec[RvecIndex];
            RvecIndex++;
        } 
		else if (Rvec[RvecIndex] > Lvec[LvecIndex])
		{
            vector[i] = Lvec[LvecIndex];
            LvecIndex++;
        } 
		else 
		{
            vector[i] = Rvec[RvecIndex];
            RvecIndex++;
        }
    }	
}
template <typename T>
void PmergeMe::sort(T& container, int begin, int end) 
{
    if (end - begin >= 1) 
	{
        int mid = (begin + end) / 2;
        sort(container, begin, mid);
        sort(container, mid + 1, end);
        merge(container, begin, mid, end);
	}
}

void PmergeMe::printContainer(void)
{
	std::cout << "Unsorted list = : \n";
	for (std::list<std::pair<int, int> > ::iterator it = _toSortList->begin(); it != _toSortList->end(); ++it)
	{
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
	std::cout << "Unsorted Vector = : \n";
	for (std::vector<std::pair<int, int> > ::iterator it = _toSortVector->begin(); it != _toSortVector->end(); ++it)
	{
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

PmergeMe::~PmergeMe( void ) 
{	
	printContainer();
	delete _toSortVector;
	delete _sortedVector;
	delete _toSortList;
	delete _sortedList;
}