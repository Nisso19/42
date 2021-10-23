/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:24:47 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/01 17:45:09 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check(char *str, int a, char c)
{
	if (str[a] == c)
		return (1);
	else
		return (0);
}

int		word_count(char *str, char c)
{
	int a;
	int i;

	a = 0;
	i = 0;
	if (str[a] && !check(str, a, c))
		i++;
	while (str[a])
	{
		if (check(str, a, c))
		{
			while (check(str, a, c))
			{
				a++;
				if (!str[a])
					return (i);
			}
			i++;
		}
		a++;
	}
	return (i);
}

int		len(char *str, int a, char c)
{
	int	b;

	b = 0;
	while (!check(str, a, c) && str[a])
	{
		a++;
		b++;
	}
	return (a);
}

char	*ft_cpy(char *dest, char *str, int a, char c)
{
	int b;

	b = 0;
	while (!check(str, a, c) && str[a])
	{
		dest[b] = str[a];
		a++;
		b++;
	}
	dest[b] = '\0';
	return (dest);
}

char	**ft_split(const char *stre, char c)
{
	char	**tab;
	char	*str;
	int		a;
	int		b;

	str = (char *)stre;
	tab = (char**)malloc(sizeof(char*) * (word_count(str, c) + 1));
	a = 0;
	b = 0;
	while (str[a])
	{
		if (!check(str, a, c) && str[a])
		{
			tab[b] = (char*)malloc(sizeof(char) * (len(str, a, c) + 1));
			ft_cpy(tab[b], str, a, c);
			b++;
			while (!check(str, a, c) && str[a])
				a++;
		}
		else
			a++;
	}
	tab[b] = 0;
	return (tab);
}
