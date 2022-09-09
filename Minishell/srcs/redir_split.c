#include "../includes/minishell.h"

int		redir_check(char *str, int a)
{
	if (str[a] == '<' || str[a] == '>')
		return (1);
	return (0);
}

char	*redir_cpy(char *dest, char *str, int a, int quote)
{
	int b;

	b = 0;
	if ((str[a] && (redir_check(str, a))) || quote)
		while (str[a] && (redir_check(str, a) || quote))
		{
			check_quotes(str[a], &quote);
			dest[b] = str[a];
			a++;
			b++;
		}
	else
		while (str[a] && (!redir_check(str, a) || quote))
		{
			check_quotes(str[a], &quote);
			dest[b] = str[a];
			a++;
			b++;
		}
	dest[b] = '\0';
	return (dest);
}

int		redir_len(char *str, int a)
{
	int	b;
	int quote;

	b = 0;
	quote = 0;
	if ((str[a] && (!redir_check(str, a))) || quote)
		while (str[a] && (!redir_check(str, a) || quote))
		{
			check_quotes(str[a], &quote);
			a++;
			b++;
		}
	else if(str[a] || quote)
		while (str[a] && (redir_check(str, a) || quote))
		{
			check_quotes(str[a], &quote);
			a++;
			b++;
		}
	return (b);
}

char		*redir_create(char *str, int *a)
{
	int 	quote;
	char	*ret;

	quote = 0;
	ret = (char*)malloc(sizeof(char) * (redir_len(str, *a) + 1));
	if (!ret)
		return (NULL);
	redir_cpy(ret, str, *a, quote);
	if (redir_check(str, *a))
		while (redir_check(str, *a))
			(*a)++;
	else
		while (str[*a] && (check_quotes(str[*a], &quote)
		|| !redir_check(str, *a)))
			(*a)++;
	(*a)--;
	return(ret);
}

int		redir_word_count(char *str)
{
	int a;
	int i;
	int quote;

	a = -1;
	i = 0;
	quote = 0;
	while (str[++a])
		if (!check_quotes(str[a], &quote) && redir_check(str, a))
		{
			i++;
			while (redir_check(str, a))
				a++;
			a--;
		}
		else if (++i)
		{
			while (str[a] && (check_quotes(str[a], &quote)
			|| !redir_check(str, a)))
				a++;
			a--;
		}
	return (i);
}

char	**ft_redir_n_quotes(const char *stre, t_data *data)
{
	char	**tab;
	char	*str;
	int		a;
	int		b;
	int		quote;

	str = (char *)stre;
	tab = (char**)malloc(sizeof(char*) * (redir_word_count(str) + 1));
	if (!tab)
		return (0);
	a = -1;
	b = 0;
	quote = 0;
	while (str[++a])
	{
		tab[b] = redir_create(str, &a);
		if (!tab[b])
			return (0);
		b++;
	}
	tab[b] = NULL;
	return (split_final_check(tab, quote, data));
}
