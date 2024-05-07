/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:50:02 by yaainouc          #+#    #+#             */
/*   Updated: 2024/02/02 17:50:03 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_H
# define SPAN_CLASS_H

# include <algorithm>
# include <iostream>
# include <vector>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const & src);
		~Span();
		Span &	operator=(Span const & src);
		void addNumber(int value);
		size_t shortestSpan();
		size_t longestSpan();
		template <typename T>
				void	addMultipleNumbers(typename T::const_iterator begin, typename T::const_iterator end)
		{
			if(std::distance(begin, end) <= 0)
				throw(std::range_error(std::string("Incorrect array size")));
			this->_array.insert(this->_array.end(), begin, end);
		}
		std::vector<int>::const_iterator getBegin() const;
		std::vector<int>::const_iterator getEnd() const;

	private:
		size_t				_max_Size;
		std::vector<int>	_array;
};
std::ostream &operator<<(std::ostream &flux, Span const& b);
#endif