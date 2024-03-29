#include "../includes/minishell.h"

int     substitute_expansion(char **word, char **str)
{
    free(*word);
    *word = *str;
    return (1);
}

int     resolve_expansion(char *exp, char **str)
{
    char    *value;
    char    *tmp;

    value = getenv(exp);
    free(exp);
    if (!*str)
        return (0);
    if (!value)
        return(1);
    tmp = *str;
    *str = ft_strjoin(*str, value);
    free(tmp);
    if (!*str)
        return (0);
    return (1);
}

int     delimit_expansion(char *word, int *i, char **str)
{
    char    *exp;
    char    buf[20];
    int     b;

    exp = NULL;
    b = 0;
    ft_bzero(buf, sizeof(char) * 20);
    (*i)++;
    if (word[*i] != '_' && !ft_isalpha(word[*i]))
        return (1);
    while (word[*i] == '_' || ft_isalnum(word[*i]))
    {
        buf[b++] = word[(*i)++];
        if (b >= 19 && !buffer_flush(buf, &exp, &b))
        {
            free(*str);
            return (0);
        }
    }
    if (!buffer_flush(buf, &exp, &b) || !resolve_expansion(exp, str))
        {
            free(*str);
            return (0);
        }
    return (1);
}

int     find_expansions(char  **word, int i, int b, int quote)
{
    char    *str;
    char    buf[20];

    str = NULL;
    ft_bzero(buf, sizeof(char) * 20);
    while ((*word)[++i])
    {
        if (check_quotes((*word)[i], &quote) != 1 && (*word)[i] == '$')
        {
            buffer_flush(buf, &str, &b);
            if (!delimit_expansion(*word, &i, &str))
                return (clean_free((void**)word));
            i--;
        }
        else
            buf[b++] = (*word)[i];
        if (b >= 19 && !buffer_flush(buf, &str, &b))
            return (clean_free((void**)word));
    }
    if (!buffer_flush(buf, &str, &b))
        return (clean_free((void**)word));
    return (substitute_expansion(word, &str));
}

int     parameter_expansions(t_data *data)
{
    int     i;
    int     y;
    t_input *input;
    t_token *token;

    i = 0;
    input = data->input;
    while(input[i].string)
    {
        y = -1;
        token = input[i].token;
        while (token[++y].word)
        {
            find_expansions(&(token[y].word), -1, 0, 0);
            if (!token[y].word)
                return (0);
        }
        i++;
    }
    return (1);
}
