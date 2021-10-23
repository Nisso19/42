#include "get_next_line.h"

int gnl_loop(char *tab[4096], int fd, char *buf)
{
	char *temp_tab;
	int i;

	i = 0;
	while((!tab[fd] || !ft_strchr(tab[fd], '\n')) && 
			(i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if(!tab[fd])
		{
			free(tab[fd]);
			if(!(tab[fd] = ft_strdup(buf)))
				return(0);
		}
		else
		{
			temp_tab = tab[fd];
			if(!(tab[fd] = ft_strjoin(tab[fd], buf)))
				return(0);
			free(temp_tab);
		}
	}
	if(i < 1 && (!tab[fd] || !tab[fd][0]))
		return(0);
	return(1);
}
char *get_next_line(int fd)
{
	char *buf;
	char *str;
	char *temp_tab;
	static char *tab[4096];

	if(!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return(NULL);
	if(read(fd, buf, 0) || !(gnl_loop(tab, fd, buf)))
	{
		free(buf);
		return(NULL);
	}
	free(buf);
	if(!ft_strchr(tab[fd], '\n'))
	{
		str = ft_strdup(tab[fd]);
		free(tab[fd]);
		tab[fd] = NULL;
		return(str);
	}
	str = ft_substr(tab[fd], 0, ft_strchr(tab[fd], '\n') - tab[fd] + 1);
	temp_tab = tab[fd];
	tab[fd] = ft_strdup(ft_strchr(tab[fd], '\n') + 1);
	free(temp_tab);
	return(str);
}

/*
**int main(int argv, char **argc)
**{
**	char *str;
**	(void)argv;
**	int fd;
**
**	fd = open(argc[1], O_RDONLY);
**	while((str = get_next_line(fd)))
**		printf("str = [%s] \n",str);
**}
*/
