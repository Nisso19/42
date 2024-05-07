/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:38 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:28:39 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void iter(T& array, std::size_t lenght, F function)
{
	for (std::size_t i = 0; i < lenght; i++)
		function(array[i]);
	return;
}

template <typename T>
void increment(T& value)
{
	value += 1;
}

template <typename T>
void decrement(T& value)
{
	value -= 1;
}

#endif