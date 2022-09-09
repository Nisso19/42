/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:49:16 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/02 15:47:04 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	while (a > -1)
	{
		if (str[a] == c)
			return ((char *)str + a);
		a--;
	}
	return (0);
}
