#include "../includes/minishell.h"

int		len(char *str, int a, char *c)
{
	int	b;
	int quote;

	b = 0;
	quote = 0;
	while (str[a] && (!split_check(str, a, c) || quote))
	{
		split_check_quotes(str, a, &quote);
		a++;
		b++;
	}
	return (b);
}

char	*ft_cpy(char *dest, char *str, int a, char *c)
{
	int b;
	int quote;

	b = 0;
	while (str[a] && (!split_check(str, a, c) || quote))
	{
		split_check_quotes(str, a, &quote);
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

char	**ft_split_n_quotes(const char *stre, char *c)
{
	char	**tab;
	char	*str;
	int		a;
	int		b;
	int		quote;

	str = (char *)stre;
	tab = (char**)malloc(sizeof(char*) * (split_word_count(str, c) + 1));
	a = -1;
	b = 0;
	quote = 0;
	while (str[++a])
		if (str[a] && (!split_check(str, a, c)))
		{
			tab[b] = (char*)malloc(sizeof(char) * (len(str, a, c) + 1));
			ft_cpy(tab[b], str, a, c);
			b++;
			while (str[a] && (split_check_quotes(str, a, &quote)
				|| !split_check(str, a, c)))
				a++;
			a--;
		}
	tab[b] = 0;
	return (final_check(tab, quote));
}
