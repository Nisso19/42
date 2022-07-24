/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:48:14 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/11 14:49:38 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	a;
	int		b;

	a = 0;
	b = 0;
	if (!(s2[0]))
		return ((char*)s1);
	while (s1[a] && a < len)
	{
		b = 0;
		while (s1[a] == s2[b] && s1[a] && a < len)
		{
			a++;
			b++;
		}
		if (!s2[b])
			return ((char*)s1 + a - b);
		else if (!(s1[a]))
			break ;
		else
			a = a - b;
		a++;
	}
	return (0);
}
