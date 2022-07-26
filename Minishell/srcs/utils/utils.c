#include "../../includes/minishell.h"

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