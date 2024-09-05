#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int *array, int array_size, bool container ) : _container( container )
{
	_toSortVector = new std::vector<std::pair<int, int> >;
	_sortedVector = new std::vector<int>();
	_toSortList = new std::list<std::pair<int, int> >;
	_sortedList = new std::list<int>();
	_odd = 0;
	createVectorY(array_size);
	if (array_size % 2)
	{
		_odd = 1;
		_straggler = array[array_size - 1];
		array[array_size - 1 ] = 0;
	}
	if ( container == 0 )
	{
		if(array_size == 1)
		{
			_sortedVector->push_back(_straggler);
			return;
		}
		if(_fillVectorContainer(array, array_size)!= -1)
			sortVector();
	}
	else if ( container == 1 )
	{
		if(array_size == 1)
		{
			_sortedList->push_back(_straggler);
			return;
		}
		if(_fillListContainer(array, array_size) != -1)
			sortList();
	}

}

int PmergeMe::_fillVectorContainer(int* array, int array_size)
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
	if((*_toSortVector).size() <= 1 && _odd == 0)
	{
		_sortedList->push_back(_toSortVector->begin()->first);
		_sortedList->push_back(_toSortVector->begin()->second);
		return(-1);
	}
	else
		sort(*_toSortVector, 0, _toSortVector->size() - 1);
	return(0);
}

int PmergeMe::_fillListContainer(int* array, int array_size)
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
	if((*_toSortList).size() <= 1 && _odd == 0)
	{
		_sortedList->push_back(_toSortList->begin()->second);
		_sortedList->push_back(_toSortList->begin()->first);
		return(-1);
	}
	else
		sort(*_toSortList, 0, _toSortList->size() - 1);
	return(0);
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
	std::advance(ListBegin, mid + 1);
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

void PmergeMe::sortVector(void)
{
	int i = 0;
	_sortedVector->push_back(_toSortVector->begin()->second);
	for (std::vector<std::pair<int, int> > ::iterator it = _toSortVector->begin(); it != _toSortVector->end(); ++it)
	{
	_sortedVector->push_back(it->first);
	}
	std::vector<int> toInsert = toInsertCreationVector();
	while(toInsert[i])
	{
	int test = binarySearchVector(toInsert[i], 0, (*_sortedVector).size() - 1);
	std::vector<int> ::iterator it = _sortedVector->begin() + test;
	(*_sortedVector).insert(it, toInsert[i]);
	i++;
	}
}

void PmergeMe::sortList(void)
{
	int i = 0;
	_sortedList->push_back(_toSortList->begin()->second);
	for (std::list<std::pair<int, int> > ::iterator it = _toSortList->begin(); it != _toSortList->end(); ++it)
	{
	_sortedList->push_back(it->first);
	}
	std::list<int> toInsert = toInsertCreationList();
	while((size_t)i < toInsert.size())
	{
	std::list<int>::iterator it = toInsert.begin();
	std::advance(it, i);
	int test = binarySearchList((*it), 0, (*_sortedList).size() - 1);
	std::list<int> ::iterator it2 = _sortedList->begin();
	std::advance(it2, test);
	(*_sortedList).insert(it2, (*it));
	i++;
	}
}

int PmergeMe::binarySearchVector(int value, int start, int end)
{
   int mid = (start + end + 1)  / 2;
	
  if ((*_sortedVector)[mid] == value || end < start)
    return mid;
  else if ((*_sortedVector)[mid] > value)
  	end = mid - 1;
  else if ((*_sortedVector)[mid] < value)
    start = mid + 1;
	return  binarySearchVector(value, start, end);
}

int PmergeMe::binarySearchList(int value, int start, int end)
{
   int mid = (start + end + 1)  / 2;

   std::list<int>::iterator it = _sortedList->begin();	
   std::advance(it, mid);
  if ((*it) == value || end < start)
    return mid;
  else if ((*it) > value)
  	end = mid - 1;
  else if ((*it) < value)
    start = mid + 1;
	return  binarySearchList(value, start, end);
}

std::list<int> PmergeMe::toInsertCreationList()
{
	std::list<int> toInsert;
	int size =  _toSortVector->size();
	if(size == 0 && _odd == 1)
	{
		toInsert.push_back(_straggler);
		return(toInsert);
	}
	if(_odd == 1)
		size += 1;
	if(size > 4)
	{
	std::list<int> listY;
	listY = createListY(size);
	int i = 0;
	int prev_number = 0;
	std::list<int>::iterator it = listY.begin();
	std::list<std::pair< int, int > >::iterator sortIt = _toSortList->begin();
	int index = (*it);
	std::advance(sortIt, index);
	while(i < size)
	{
		prev_number = (*it);
		while(index != prev_number)
		{
		toInsert.push_back((*sortIt).second);
		index--;
		std::advance(sortIt, index);
		}
		prev_number = (*it);
		i++;
		std::advance(it, i);
		index = (*it);
	}
	}
	else
	{
	for (std::list<std::pair<int, int> > ::iterator it = _toSortList->begin(); it != _toSortList->end(); ++it)
	{
		if(it == _toSortList->begin())
			std::advance(it, 1);
		toInsert.push_back(it->second);
	}
	}
	if(_odd == 1)
	{
		toInsert.push_back(_straggler);
		std::cout << "je suis la\n";
	}
	return(toInsert);
}

std::vector<int> PmergeMe::toInsertCreationVector()
{
	std::vector<int> toInsert;
	int size =  _toSortVector->size();
	if(size == 0 && _odd == 1)
	{
		toInsert.push_back(_straggler);
		return(toInsert);
	}
	if(_odd == 1)
		size += 1;
	if(size > 4)
	{
	std::vector<int> vectorY;
	vectorY = createVectorY(size);
	int i = 0;
	int prev_number = 0;
	int index = vectorY[i];
	while(vectorY[i])
	{
		while(index != prev_number)
		{
		toInsert.push_back((*_toSortVector)[index].second);
		index--;
		}
		prev_number = vectorY[i];
		i++;
		index = vectorY[i];
	}
	}
	else
	{
	for (std::vector<std::pair<int, int> > ::iterator it = _toSortVector->begin() + 1; it != _toSortVector->end(); ++it)
	{
		toInsert.push_back(it->second);
	}
	}
	if(_odd == 1)
	{
		std::cout << _straggler << std::endl;
		toInsert.push_back(_straggler);
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
		vectorY.push_back(temp);
		i++;
	}
	return ( vectorY );
}

std::list<int> PmergeMe::createListY(int size)
{
	std::list<int> listY;
	int i = 3;
	while ( _getIndex(i) < size - 1 )
	{
		int temp = _getIndex(i);
		listY.push_back(temp);
		i++;
	}
	return ( listY );
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
	// 	std::cout << it->first << std::endl;
	// 	std::cout << it->second << std::endl;
	// }
	if(_container == 0)
	{
	std::cout << "Sorted Vector = : \n";
	for (std::vector<int> ::iterator it = _sortedVector->begin(); it != _sortedVector->end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	}
	else
	{
	std::cout << "Sorted List = : \n";
	for (std::list<int> ::iterator it = _sortedList->begin(); it != _sortedList->end(); ++it)

	{
		std::cout << (*it) << std::endl;
	}
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