/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:48 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:28:49 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>

Array<T>::Array(void) : _ptr(NULL), _size(0) 
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _ptr(new T[n]), _size(n) 
{
}

template<typename T>
Array<T>::Array(Array const & src) : _ptr(new T[src._size]), _size(src._size)
{
	for(unsigned int i = 0; i < this->_size ; i++)
		this->_ptr[i] = src._ptr[i];
}

template<typename T>	
Array<T>::~Array(void)
{ 
	delete [] _ptr; 
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T> const& src)
{
	if (this == &src)
		return (*this);
	if (this->_size != src._size) 
	{
		delete [] _ptr;
		this->_size = src._size;
		this->_ptr = new T[this->_size];
	}
	for (unsigned int i = 0; i < this->_size; i++)
			this->_ptr[i] = src._ptr[i];
		return (*this);
}
template<typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if(index >= this->_size || index < 0)
		throw (std::out_of_range(std::string("Out of range")));
	return (this->_ptr[index]);
}
