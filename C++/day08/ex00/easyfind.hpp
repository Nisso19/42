/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:49:41 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:49:42 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <string>
#include <iterator>
#include <stdexcept>

template<typename T>
typename T::const_iterator easyfind(T const & container, int value)
{
	typename T::const_iterator tab;

	tab = std::find(container.begin(), container.end(), value);
	if (tab == container.end())
		throw (std::out_of_range("Value not found"));
	else
		return(tab);
}

#endif