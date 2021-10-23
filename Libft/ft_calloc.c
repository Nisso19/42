/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:19:10 by yaainouc          #+#    #+#             */
/*   Updated: 2020/12/01 14:16:39 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	if (!(str = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(str, nmemb);
	return (str);
}
