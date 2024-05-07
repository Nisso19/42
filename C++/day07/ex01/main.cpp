/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:40 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:28:41 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void capitalize(std::string& str)
{
	for (unsigned int i = 0; i < str.size(); ++i)
	{
			str[i] = std::toupper(str[i]);
	}
}


int main(void)
{
	int array[3] = {4, 5, 3};
	for (int i = 0; i < 3; ++i)
		std::cout << array[i] << std::endl;	
	std::cout << "-----" << std::endl;	
	iter(array, 3, increment<int>);
	for (int i = 0; i < 3; ++i)
		std::cout << array[i] << std::endl;	
	std::cout << std::endl;

	double array2[3] = {21, 13, 81.36};
	for (int i = 0; i < 3; ++i)
		std::cout << array2[i] << std::endl;
	std::cout << "-----" << std::endl;	
	iter(array2, 3, decrement<double>);
	for (int i = 0; i < 3; ++i)
		std::cout << array2[i] << std::endl;
	std::cout << std::endl;

	std::string array3[3] = {"c", "TeSt 2 ?", "Test test 3"};
	for (int i = 0; i < 3; ++i)
		std::cout << array3[i] << std::endl;
	std::cout << "-----" << std::endl;	
	iter(array3, 3, capitalize);
	for (int i = 0; i < 3; ++i)
		std::cout << array3[i] << std::endl;	
	return (0);
}