/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:20:34 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/01 14:24:10 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		a;
	int		n2;

	a = 0;
	n2 = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n2 != 0)
	{
		n2 = n2 / 10;
		a++;
	}
	a = n < 0 ? a + 1 : a;
	if (!(str = (char*)malloc(sizeof(char) * (a + 1))))
		return (0);
	str[a--] = '\0';
	str[0] = '-';
	while (n != 0)
	{
		str[a--] = n < 0 ? n % 10 * (-1) + 48 : n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
