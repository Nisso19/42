/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:44:22 by yaainouc          #+#    #+#             */
/*   Updated: 2020/11/28 14:44:33 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int p;
	unsigned int u;

	i = 0;
	p = 0;
	u = 0;
	while (dest[i] != '\0')
		++i;
	while (src[u] != '\0')
		++u;
	if (size <= i)
		u = u + size;
	else
		u = u + i;
	while (src[p] != '\0' && i + 1 < size)
	{
		dest[i] = src[p];
		p++;
		i++;
	}
	dest[i] = '\0';
	return (u);
}
