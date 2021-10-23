/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:47:33 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/02 15:45:08 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			a;
	unsigned char	*ss1;
	unsigned char	*ss2;

	a = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	if (len == 0)
		return (0);
	while (ss1[a] && ss2[a] && ss1[a] == ss2[a] && a < len - 1)
		a++;
	return (ss1[a] - ss2[a]);
}
