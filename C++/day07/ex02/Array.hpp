/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:46 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:28:47 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{

	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const& toCopy);
		Array& operator=(Array<T> const& src);
		T& operator[](unsigned int index);
		~Array(void);
		unsigned int size() const;

	private:
		T* _ptr;
		unsigned int _size;
};

#include "Array.tpp"

#endif