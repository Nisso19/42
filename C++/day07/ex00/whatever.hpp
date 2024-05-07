/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:34 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:28:35 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const& max(const T& a, const T& b)
{
	if (a > b)
		return(a);
	else
		return(b);
}

template <typename T>
T const& min(const T& a, const T& b)
{
	if (a < b)
		return(a);
	else
		return(b);
}
#endif