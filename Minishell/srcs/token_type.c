#include "../includes/minishell.h"


void check_arrow(char **tab)

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
			while (str[a] && (check_quotes(str[a], &quote)
				|| !split_check(str, a, c)))
				a++;
			a--;
		}
	tab[b] = 0;
	return (final_check(tab, quote));
}

int		split_word_count(t_token *tab)
{
	int a;
	int i;
	int quote;

	a = 0;
	i = 0;
	quote = 0;
	if (str[a] && (check_quotes(str[a], &quote) || split_check(str, c)))
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

int		split_check(char *str, int a, char *c)
{
	int i;

	i = 0;
	while(c[i])
	{
		if (str[a] == "<")
			return (1);
		i++;
	}
	return (0);
}