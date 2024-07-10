/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:49:47 by yaainouc          #+#    #+#             */
/*   Updated: 2024/07/09 19:43:41 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <list>
#include "Span.hpp"

static void out_of_range_test(void)
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(100);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void basic_test(void)
{
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Sp: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Sp: " << sp.longestSpan() << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp2(sp);
	std::cout << "Shortest Sp2: " << sp2.shortestSpan() << std::endl;	
	std::cout << "longest Sp2: " << sp2.longestSpan() << "\n\n";

	Span sp3(2);
	sp3 = sp;
	std::cout << "Shortest Sp3: " << sp3.shortestSpan() << std::endl;	
	std::cout << "longest Sp3: " << sp3.longestSpan() << "\n\n";
}

static void several_number_test(void)
{
	srand(time(0));
	Span sp = Span(10);
	try
	{
		for (int i = 0; i < 10; ++i)
			sp.addNumber(rand() % 100000);
		std::cout << "Shortest Sp: " << sp.shortestSpan() << std::endl;
		std::cout << "longest Sp: " << sp.longestSpan() << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp2 = Span(20000);
	try
	{
		sp2.addMultipleNumbers<std::vector<int> >(sp.getBegin(), sp.getEnd());
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		for (int i = 0; i < 10; ++i)
			sp2.addNumber(rand() % 100000);
		std::cout << "Shortest Sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest Sp2: " << sp2.longestSpan() << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void other_container_test(void)
{
	std::list<int> lst(10, 5);
	Span sp = Span(200);
	std::list<int>::iterator begin = lst.begin();
	std::list<int>::iterator end = lst.end();

	try
	{
		sp.addMultipleNumbers<std::list<int> >(begin, end);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sp << std::endl;
	try
	{
		sp.addMultipleNumbers<std::list<int> >(end, end);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	out_of_range_test();
	basic_test();
	several_number_test();
	other_container_test();
	return (0);
}