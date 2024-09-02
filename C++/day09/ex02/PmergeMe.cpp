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
	createVectorY(array_size);
	if (array_size % 2)
	{
		_straggler = array[array_size - 1];
		array[array_size - 1 ] = 0;
	}
	if ( container == 0 )
	{
		_fillVectorContainer(array, array_size);
		sortVector();
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
	// std::cout << "Unsorted list = : \n";
	// for (std::list<std::pair<int, int> > ::iterator it = _toSortList->begin(); it != _toSortList->end(); ++it)
	// {
	// 	std::cout << it->first << std::endl;
	// 	std::cout << it->second << std::endl;
	// }
	// std::cout << "Unsorted Vector = : \n";
	// for (std::vector<std::pair<int, int> > ::iterator it = _toSortVector->begin(); it != _toSortVector->end(); ++it)
	// {
	// 	// std::cout << it->first << std::endl;
	// 	std::cout << it->second << std::endl;
	// }
	std::cout << "Sorted Vector = : \n";
	for (std::vector<int> ::iterator it = _sortedVector->begin(); it != _sortedVector->end(); ++it)

	{
		std::cout << (*it) << std::endl;
	}
}

void PmergeMe::sortVector(void)
{
	int i = 0;
	int size = _toSortVector->size() / 2;
	_sortedVector->push_back(_toSortVector->begin()->second);
	for (std::vector<std::pair<int, int> > ::iterator it = _toSortVector->begin(); it != _toSortVector->end(); ++it)
	{
	_sortedVector->push_back(it->first);
	}
	std::vector<int> toInsert = toInsertCreation();
	int test = binarySearch(toInsert[10], 0, (*_sortedVector).size() - 1);
	std::vector<int> ::iterator it = _sortedVector->begin() + test + 1;
	(*_sortedVector).insert(it, toInsert[10]);
	std::cout << test << " valeur = " << toInsert[10] << std::endl;
	// while(added == 0)
	// {
	// if ( (*_sortedVector)[size] <= (*_toSortVector)[vectorY[i]].second)
	// {

	// }
	// }	
}

int PmergeMe::binarySearch(int value, int start, int end)
{
   int mid = (start + end)  / 2;
	
  if ((*_sortedVector)[mid] == value || (end - start < 0))
    return mid;
  else if ((*_sortedVector)[mid] > value)
  	end = mid - 1;
  else if ((*_sortedVector)[mid] < value)
    start = mid + 1;
	return  binarySearch(value, start, end);
}

std::vector<int> PmergeMe::toInsertCreation()
{
	std::vector<int> toInsert;
	std::vector<int> vectorY;
	vectorY = createVectorY(_toSortVector->size());
	int i = 0;
	int prev_number = 0;
	int index = vectorY[i];
	while(vectorY[i])
	{
		while(index != prev_number)
		{
		toInsert.push_back((*_toSortVector)[index].second);
		// std::cout << index << std::endl;
		index--;
		}
		prev_number = vectorY[i];
		i++;
		index = vectorY[i];
	}
	return(toInsert);
}

int PmergeMe::_getIndex( int n )
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	return ( _getIndex( n - 1 ) + 2 * _getIndex( n - 2 ) );
}

std::vector<int> PmergeMe::createVectorY(int size)
{
	std::vector<int> vectorY;
	int i = 3;
	while ( _getIndex(i) < size - 1 )
	{
		int temp = _getIndex(i);
		// std::cout << temp << std::endl;
		vectorY.push_back(temp);
		i++;
	}
	return ( vectorY );
}



PmergeMe::~PmergeMe( void ) 
{	
	printContainer();
	delete _toSortVector;
	delete _sortedVector;
	delete _toSortList;
	delete _sortedList;
}