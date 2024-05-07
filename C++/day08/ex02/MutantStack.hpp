/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:50:12 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:50:13 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
		public:
		MutantStack(void){};
		MutantStack(MutantStack<T> const& toCopy): std::stack<T>(toCopy.std::stack<T>::c) {};
		MutantStack<T> const& operator=(MutantStack<T> const& src)
		{
			if (this != &src)
				this->std::stack<T>::c = src.std::stack<T>::c;
			return (*this);
		};
		~MutantStack(void){};
		typedef typename std::stack<T>::container_type::iterator					iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		
		
		MutantStack<T>::iterator	begin(void)
		{
			return (std::stack<T>::c.begin());
		}
		
		MutantStack<T>::iterator	end(void)
		{
			return (std::stack<T>::c.end());
		}
		
		MutantStack<T>::const_iterator	cbegin(void)
		 {
			return (std::stack<T>::c.begin());
		}
		
		MutantStack<T>::const_iterator	cend(void)
		{
			return (std::stack<T>::c.end());
		}
		
		MutantStack<T>::reverse_iterator	rbegin(void)
		{
			return (std::stack<T>::c.rbegin());
		}
		
		MutantStack<T>::reverse_iterator	rend(void)
		{
			return (std::stack<T>::c.rend());
		}

		MutantStack<T>::const_reverse_iterator	crbegin(void)
		{
			return (std::stack<T>::c.rbegin());
		}
		
		MutantStack<T>::const_reverse_iterator	crend(void)
		{
			return (std::stack<T>::c.rend());
		}

};

#endif