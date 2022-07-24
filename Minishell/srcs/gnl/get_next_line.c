/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:30:20 by yaainouc          #+#    #+#             */
/*   Updated: 2021/11/24 16:35:07 by yaainouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_join(int fd, char *tab[4096], char *buf)
{
	char	*temp_tab;

	temp_tab = tab[fd];
	tab[fd] = ft_strjoin(tab[fd], buf);
	if (!tab[fd])
		return (0);
	free(temp_tab);
	return (1);
}

int	gnl_loop(char *tab[4096], int fd, char *buf)
{
	int		i;

	i = 0;
	while (!tab[fd] || !ft_strchr(tab[fd], '\n'))
	{
		i = read(fd, buf, 30);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		if (!tab[fd])
		{
			free(tab[fd]);
			tab[fd] = ft_strdup(buf);
			if (!tab[fd])
				return (0);
		}
		else
		{
			if (ft_join(fd, tab, buf) == 0)
				return (0);
		}
	}
	if (i < 1 && (!tab[fd] || !tab[fd][0]))
		return (0);
	return (1);
}

void	ft_free(int fd, char *tab[4096], int c, char *buf)
{
	if (c == 1)
	{
		free(tab[fd]);
		tab[fd] = NULL;
	}
	else if (c == 2)
	{
		free(buf);
		if (fd >= 0)
			free(tab[fd]);
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*str;
	char		*temp_tab;
	static char	*tab[4096];

	buf = malloc((30 + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (read(fd, buf, 0) || !(gnl_loop(tab, fd, buf)))
	{
		ft_free(fd, tab, 2, buf);
		return (NULL);
	}
	free(buf);
	if (!ft_strchr(tab[fd], '\n'))
	{
		str = ft_strdup(tab[fd]);
		ft_free(fd, tab, 1, buf);
		return (str);
	}
	str = ft_substr(tab[fd], 0, ft_strchr(tab[fd], '\n') - tab[fd] + 1);
	temp_tab = tab[fd];
	tab[fd] = ft_strdup(ft_strchr(tab[fd], '\n') + 1);
	free(temp_tab);
	return (str);
}
