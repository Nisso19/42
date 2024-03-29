#include "../includes/minishell.h"

int         pipelines_check(char *s)
{
    int i;
    int c_found;

    i = 0;
    c_found = 0;
    while(s[i])
    {
        if (!ft_strchr("| \t\n\v\f\r", s[i]))
            c_found = 1;
        else if (s[i] == '|')
        {
            if (c_found == 0)
                return (0);
            c_found = 0;
        }
        i++;
    }
    if (c_found == 0)
        return (0);
    return (1);
}

int         get_input(t_data *data)
{
    char        *line;
    char        **pipelines;
    t_input     *input;

    line = readline(0);
    if (!line)
        return (0);
    if (!pipelines_check(line))
    {
        data->errors = SYNTAX_ERROR;
        printf("test");
        return (0);
    }
    pipelines = ft_split_n_quotes(line, "|", data);
    if (!pipelines)
        return (0);
    input = init_input(pipelines);
    free(pipelines);
    if (!input)
        return (0);
    data->input = input;
    return (1);
}

char        **split_tokens(char **words, t_data *data)
{
    int     i;
    char    **tokens;
    char    **tmp;
    char    **tmp2;

    i = 0;
    tokens = NULL;
    while(words[i] != NULL)
    {
        tmp = ft_redir_n_quotes(words[i], data);
        if (tokens)
        {
            tmp2 = tmp;
            tmp = ft_tabjoin(tokens, tmp);
            free(tmp2);
            free(tokens);
        }
        tokens = tmp;
        if (!tokens)
            return (0);
        i++;
    }
    return (tokens);
}

int         get_tokens(t_data *data)
{
    int     i;
    char    **words;
    char    **tmp;
    t_input *input;

    i = 0;
    input = data->input;
    while (input[i].string)
    {
        words = ft_split_n_quotes(input[i].string, " \t\n\v\f\r", data);
        if (!words)
            return (0);
        tmp = words;
        words = split_tokens(words, data);
        free(tmp);
        if (!words)
            return (0);
        input[i].token = init_token(words);
        free(words);
        i++;
    }
    return (1);
}

int         lexer(t_data *data)
{
    if (!get_input(data)
        || !input_debug(data)
        || !get_tokens(data)
        || !parameter_expansions(data)
        || !set_type(data)
        || !tokens_debug(data))
        {
            if (data->errors == NONE) // si NONE -> erreur de malloc donc on exit
            {
                printf("malloc error\n");
                return (0);
            }
            else if (data->errors == SYNTAX_ERROR)
                printf("Syntax error\n");
        }
        return(1);
}