#include "../../includes/minishell.h"

char	**ft_tabjoin(char **tab1, char **tab2)
{
	char	**ret;
	int		len1;
	int		len2;
	int 	i;

	len1 = 0;
	len2 = 0;
	i = 0;
	if (!tab1 || !tab2)
		return (0);
	while (tab1[len1])
		len1++;
	while (tab2[len2])
		len2++;
	ret = (char **)malloc(sizeof(char*) * (len1 + len2 + 1));
	if (!ret)
		return (0);
	while (*tab1)
		ret[i++] = *(tab1++);
	while (*tab2)
		ret[i++] = *(tab2++);
	ret[i] = NULL;
	return (ret);
}

int		check_quotes(char c, int *quote)
{
	if (c == '\"')
	{
		if (*quote == 0)
			*quote = 2;
		else if (*quote == 2)
			*quote = 0;
		else if (*quote == 1)
			*quote = *quote;
	}
	else if (c == '\'')
	{
		if (*quote == 0)
			*quote = 1;
		else if (*quote == 1)
			*quote = 0;
		else if (*quote == 2)
			*quote = *quote;
	}
	return (*quote);
}

int     clean_free(void **ptr)
{
    free(*ptr);
    *ptr = NULL;
    return (0);
}

int     buffer_flush(char buf[20], char **str, int *b)
{
    char    *tmp;

    tmp = *str;
    if (*str)
        *str = ft_strjoin(*str, buf);
    else
        *str = ft_strdup(buf);
    free(tmp);
    if (!*str)
        return (0);
    ft_bzero(buf, sizeof(char) * 20);
    *b = 0;
    return (1);
}