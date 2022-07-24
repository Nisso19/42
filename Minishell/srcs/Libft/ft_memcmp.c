/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:58:24 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/01 14:58:28 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	a = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (a < n - 1 && str1[a] == str2[a])
		a++;
	return (str1[a] - str2[a]);
}
