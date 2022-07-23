#include "minishell.h"

int		check_quotes(char *str, int a, int *quote)
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

/*
int		check(char *str, int a, char c)
{
	if (str[a] == c)
		return (1);
	else
		return (0);
}
*/

int		word_count(char *str, char c)
{
	int a;
	int i;
	int quote;

	a = 0;
	i = 0;
	quote = 0;
	if (str[a] && (check_quotes(str, a, &quote) || str[a] != c))
		i++;
	while (str[a])
	{
		check_quotes(str, a, &quote);
		if (str[a] == c && !quote)
		{
			while (str[a] == c)
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
	int quote;

	b = 0;
	quote = 0;
	while (str[a] && (str[a] != c || quote))
	{
		check_quotes(str, a, &quote);
		a++;
		b++;
	}
	return (b);
}

char	*ft_cpy(char *dest, char *str, int a, char c)
{
	int b;
	int quote;

	b = 0;
	while (str[a] && (str[a] != c || quote))
	{
		check_quotes(str, a, &quote);
		dest[b] = str[a];
		a++;
		b++;
	}
	dest[b] = '\0';
	return (dest);
}

char	**final_check(char **tab, int quote)
{
	int i;

	i = -1;
	if (quote)
	{
		printf("Syntax error: unmatched quote\n");
		data.errors = SYNTAX_ERROR;
		while (tab[++i])
			free(tab[i]);
		free(tab);
		tab = NULL;
	}
	return (tab);
}

char	**ft_split_n_quotes(const char *stre, char c)
{
	char	**tab;
	char	*str;
	int		a;
	int		b;
	int		quote;

	str = (char *)stre;
	tab = (char**)malloc(sizeof(char*) * (word_count(str, c) + 1));
	a = -1;
	b = 0;
	quote = 0;
	while (str[++a])
		if (str[a] && (str[a] != c))
		{
			tab[b] = (char*)malloc(sizeof(char) * (len(str, a, c) + 1));
			ft_cpy(tab[b], str, a, c);
			b++;
			while (str[a] && (check_quotes(str, a, &quote) || str[a] != c))
				a++;
			a--;
		}
	tab[b] = 0;
	return (final_check(tab, quote));
}
