#include "../../includes/minishell.h"


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

int		split_word_count(char *str, char *c)
{
	int a;
	int i;
	int quote;

	a = 0;
	i = 0;
	quote = 0;
	if (str[a] && (check_quotes(str[a], &quote) || !split_check(str, a, c)))
		i++;
	while (str[a])
	{
		check_quotes(str[a], &quote);
		if (split_check(str, a, c) && !quote)
		{
			while (split_check(str, a, c))
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
