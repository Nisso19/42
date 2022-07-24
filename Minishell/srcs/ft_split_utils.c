#include "../includes/minishell.h"

int		split_check_quotes(char *str, int a, int *quote)
{
	if (str[a] == '\"')
	{
		if (*quote == 0)
			*quote = 2;
		else if (*quote == 2)
			*quote = 0;
		else if (*quote == 1)
			*quote = *quote;
	}
	else if (str[a] == '\'')
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

int		split_check(char *str, int a, char *c)
{
	int i;

	i = 0;
	while(c[i])
	{
		if (str[a] == c[i])
			return (1);
		i++;
	}
	return (0);
}

int		split_word_count(char *s, char *c)
{
	int a;
	int i;
	int quote;

	a = 0;
	i = 0;
	quote = 0;
	if (s[a] && (split_check_quotes(s, a, &quote) || split_check(s, a, c)))
		i++;
	while (s[a])
	{
		split_check_quotes(s, a, &quote);
		if (split_check(s, a, c) && !quote)
		{
			while (split_check(s, a, c))
			{
				a++;
				if (!s[a])
					return (i);
			}
			i++;
		}
		a++;
	}
	return (i);
}