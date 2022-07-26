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

int         get_input()
{
    char        *line;
    char        **pipelines;
    t_input     *input;

    line = get_next_line(0);
    if (!line)
        return (0);
    if (!pipelines_check(line))
    {
        data.errors = SYNTAX_ERROR;
        return (0);
    }
    pipelines = ft_split_n_quotes(line, "|");
    if (!pipelines)
        return (0);
    input = init_input(pipelines);
    free(pipelines);
    if (!input)
        return (0);
    data.input = input;
    return (1);
}

int         get_tokens()
{
    int     i;
    t_input *input;
    char    **words;

    i = 0;
    input = data.input;
    while (input[i].string)
    {
        words = ft_split_n_quotes(input[i].string, " \t\n\v\f\r");
        if (!words)
            return (0);
        input[i].token = init_token(input[i], words);
        free(words);
        i++;
    }
    return (1);
}

int         lexer()
{
    if (!get_input()
        || !input_debug()
        || !get_tokens()
        || !tokens_debug()
        || !parameter_expansions()
        || !tokens_debug())
        {
            if (data.errors == NONE) // si NONE -> erreur de malloc donc on exit
                return (0);
            else if (data.errors == SYNTAX_ERROR)
                printf("Syntax error\n");
        }
}