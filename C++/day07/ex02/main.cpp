/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:50 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:28:51 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 10

char genRandom()
{
	const char alphanum[] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	int stringLength = sizeof(alphanum) - 1;
    return alphanum[rand() % stringLength];
}

int main(int, char**)
{
	Array<char> numbers(MAX_VAL);
	char* mirror = new char[MAX_VAL];
	srand(time(NULL));
	std::cout << "---------------------char-----------------------------\n";
	std::cout << "array size = " << numbers.size() << "\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		char value = genRandom();
		numbers[i] = value;
		std::cout << "array = " << numbers[i];
		mirror[i] = value;
		std::cout << " | mirror = " << mirror[i] << std::endl;

	}
	std::cout << "---------------------int------------------------------\n";
	Array<int> numbers2(50);
	int* mirror2 = new int[MAX_VAL];
	for (int i = 0; i < MAX_VAL; i++)
	{
		const char value = rand();
		numbers2[i] = value;
		std::cout << "array = " << numbers2[i];
		mirror2[i] = value;
		std::cout << " | mirror = " << mirror2[i] << std::endl;
	}
	std::cout << "---------------------exceptions------------------------\n";
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL + 10] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete [] mirror;
	delete [] mirror2;
	return 0;
}