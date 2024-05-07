/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:49:59 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:50:00 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
Span::Span(void) : _max_Size(0), _array()
{
	return ;
}

Span::Span(unsigned int N) : _max_Size(N), _array()
{

	return ;
}

Span::Span(Span const & src) : _max_Size(src._max_Size), _array(src._array)
{
	if (this != & src)
	{
		this->_max_Size = src._max_Size;
		this->_array = src._array;
		
	}
	return ;
}

Span::~Span(void)
{
	return ;
}


void Span::addNumber(int value)
{
	if (this->_array.size() == this->_max_Size)
		throw (std::out_of_range(std::string("Array full")));
	_array.push_back(value);
}

Span &	Span::operator=(Span const & src)
{
	if (this != & src)
	{
		std::vector<int> array(src._array);
		this->_max_Size = src._max_Size;
		this->_array = src._array;
	
	}
	return(*this);
}

std::vector<int>::const_iterator Span::getBegin() const
{
	return(_array.begin());
}

std::vector<int>::const_iterator Span::getEnd() const
{
	return(_array.end());
}


size_t Span::shortestSpan()
{
	std::vector<int> temparray(_array);
	
	std::sort(temparray.begin(), temparray.end());
	std::vector<int> adj_diff(temparray);
	std::adjacent_difference(temparray.begin(), temparray.end(), adj_diff.begin());
	return(*std::min_element(++(adj_diff.begin()), adj_diff.end()));
}

size_t Span::longestSpan()
{
	return(*(std::max_element(_array.begin(), _array.end())) 
			- *(std::min_element(_array.begin(), _array.end())));
}

std::ostream &operator<<(std::ostream &flux, Span const& b)
{
	for (std::vector<int>::const_iterator it = b.getBegin(); it != b.getEnd(); ++it)
		flux << *it << " ";
	return (flux);
}