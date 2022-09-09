/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:22:58 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/02 15:10:24 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d1;
	unsigned char		*s1;
	size_t				a;

	d1 = (unsigned char *)dest;
	s1 = (unsigned char *)src;
	if (s1 < d1)
	{
		a = n;
		while (a-- > 0)
			d1[a] = s1[a];
	}
	else
	{
		a = 0;
		while (a < n)
		{
			d1[a] = s1[a];
			a++;
		}
	}
	return (d1);
}
