/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:46:51 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/02 15:58:21 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	int		b;
	char	*str;

	if (!s)
		return (0);
	a = 0;
	b = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!str)
		return (0);
	str[b] = '\0';
	while (b)
	{
		str[a] = f(a, s[a]);
		a++;
		b--;
	}
	return (str);
}
