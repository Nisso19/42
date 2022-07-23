#include "minishell.h"

t_input     *init_input(char **pipelines)
{
    t_input     *input;
    int         i;
    int         nb_pipes;

    i = -1;
    nb_pipes = 1;
    while (pipelines[++i])
        nb_pipes++;
    input = (t_input *)malloc(sizeof(t_input) * nb_pipes);
    if (!input)
        return (NULL);
    i = -1;
    while (pipelines[++i])
    {
        input[i].token = NULL;
        input[i].path = NULL;
        input[i].string = pipelines[i];
    }
    input[i - 1].is_last = 1;
    i = -1;
    return (input);
}

int         get_input(t_input **main_input)
{
    char        *line;
    char        **pipelines;
    t_input     *input;

    line = get_next_line(0);
    if (!line)
        return (0);
    pipelines = ft_split_n_quotes(line, '|');
    if (!pipelines)
        return (0);
    input = init_input(pipelines);
    if (!input)
        return (0);
    free(pipelines);
    *main_input = input;

    // DEBUG

    int i;
    i = 0;
    printf("pipelines =\n");
    while(1)
    {
        printf("[%s] ", input[i].string);
        if (input[i].is_last)
            break ;
        i++;
    }
    printf("\npipes = %d\n", i + 1);
    return (1);
}

/*
int         lexer()
{
    
}
*/