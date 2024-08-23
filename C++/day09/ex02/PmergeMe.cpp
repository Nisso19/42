#include "PmergeMe.hpp"

PmergeMe::PmergeMe( int* array, int array_size, bool container ) : _container( container )
{
	_toSortVector = new std::vector<std::pair<int, int> >;
	_sortedVector = new std::vector<int>();
	_toSortList = new std::list<int>();
	_sortedList = new std::list<int>();

    // (void)array;
    // (void)array_size;
    // (void)container;
	if (array_size % 2)
	{
		_straggler == array[array_size - 1];
		array[array_size - 1 ] == NULL;
	}
	_fillContainer(array, array_size);

	// if ( container == 0 )
	// {
	//  	_fillVectorFromArray( array, array_size );
	// }
	// else if ( container == 1 )
	// {
	//  	_fillListFromArray( array, array_size );
	// }
}

void PmergeMe::_fillContainer(int* array, int array_size)
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
	SortVector();
	// for ( int i = 0; i < array_size; i++)
	// {
		
	// 	_toSortList->push_back(array[i]);
	// 	_toSortVector->push_back(array[i]);
	// }
}


void PmergeMe::SortVector()
{
	int i = 0;
	int size = _toSortVector->size();
	int value = 1;
	while (value < size)
	{
	size = size / 2;
	for (std::vector<std::pair<int, int> > ::iterator it = _toSortVector->begin(); i < size; ++it)
	{
		int temp = 0;
		std::cout << "first = " << it->first << "first 2 = " << (it + value)->first << std::endl;
		if(it->first < (it + value)->first)
		{	
			temp = it->first;
			it->first = (it + value)->first;
			(it + value)->first = temp;
		}
		it += value;
		i++;
	}
	value = value * 2;
	i = 0;
	printContainer();
	}
}

void PmergeMe::printContainer(void)
{
	// std::cout << "Unsorted list = : \n";
	// for (std::list<int>::iterator it = _toSortList->begin(); it != _toSortList->end(); ++it)
	// {
	// 	std::cout << *it << std::endl;
	// }
	std::cout << "Unsorted Vector = : \n";
	for (std::vector<std::pair<int, int> > ::iterator it = _toSortVector->begin(); it != _toSortVector->end(); ++it)
	{
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

PmergeMe::~PmergeMe( void ) 
{
	delete _toSortVector;
	delete _sortedVector;
	delete _toSortList;
	delete _sortedList;
}