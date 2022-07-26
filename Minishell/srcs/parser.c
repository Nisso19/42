int		split_check(t_token *token)
{
	int     i;
    int     quote;
    char    *res;

    quote = 0;
	i = 0;
    res = (char *)malloc(sizeof(char) * ft_strlen(str));
    ft_bzero(res, ft_strlen(str));
    while (str[i])
    {
        if(check_quotes(str[i], &quote) == 0)
        {
		    if (str[i] == '<' || str[i] == '>')
            {
                i++;
                if (str[i] == str[i - 1])
                    i++;
                if (str[i])
                    word_after_redir(str[i]);
                else
                    word_after_redir(token d après);
            }
        }
        else
            res[]
        if (str[i])
		    i++;
	}
	return (1);
}