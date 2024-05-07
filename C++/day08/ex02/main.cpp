/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:50:05 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:50:06 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include "MutantStack.hpp"



template <typename T>
void	regular_iterator_test(MutantStack<T>& mstack)
{
	MutantStack<int>::container_type::iterator it = mstack.begin();
	MutantStack<int>::container_type::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}


template <typename T>
void	const_iterator_test(MutantStack<T>& mstack)
{
	MutantStack<int>::const_iterator it = mstack.cbegin();
	MutantStack<int>::const_iterator ite = mstack.cend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
void reverse_iterator_test(MutantStack<T>& mstack)
{
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
void const_reverse_iterator_test(MutantStack<T>& mstack)
{
	MutantStack<int>::const_reverse_iterator it = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator ite = mstack.crend();	
	++it;
	--it;
	while (it != ite)
	{
		//*it = *it * 2;
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void subject()
{
std::list<int> pstack;
pstack.push_back(5);
pstack.push_back(17);
std::cout << pstack.back() << std::endl;
pstack.pop_back();
std::cout << pstack.size() << std::endl;
pstack.push_back(3);
pstack.push_back(5);
pstack.push_back(737);
//[...]
pstack.push_back(0);
std::list<int>::iterator it = pstack.begin();
std::list<int>::iterator ite = pstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}

std::cout << "------------------Mutantstack------------------\n";

MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator at = mstack.begin();
MutantStack<int>::iterator ate = mstack.end();
++at;
--at;
while (at != ate)
{
std::cout << *at << std::endl;
++at;
}
std::stack<int> s(mstack);
}


void int_test(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top of mstack: " << mstack.top() << std::endl;
	std::cout << "size of mstack before pop: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "size of mstack after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	srand(time(0));
	for (int i = 0; i < 5; ++i)
		mstack.push(rand() % 2000);
	regular_iterator_test(mstack);
	const_iterator_test(mstack);
	reverse_iterator_test(mstack);
	const_reverse_iterator_test(mstack);
	std::cout << "top of mstack: " << mstack.top() << std::endl;

}

int main(void)
{
	std::cout << "Real list:\n" << std::endl;
	subject();
	std::cout << "------------------My test----------------------" << std::endl;
	std::cout << "Int MutantStack test:\n" << std::endl;
	int_test();

	return (0);
}