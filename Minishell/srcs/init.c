#include "../includes/minishell.h"

t_input     *init_input(char **pipelines)
{
    t_input     *input;
    int         i;
    int         nb_pipes;

    i = -1;
    nb_pipes = 1;
    while (pipelines[++i])
        nb_pipes++;
    input = (t_input *)malloc(sizeof(t_input) * (nb_pipes + 1));
    if (!input)
        return (NULL);
    i = 0;
    while (pipelines[i])
    {
        input[i].token = NULL;
        input[i].path = NULL;
        input[i].string = pipelines[i];
        i++;
    }
    input[i].string = NULL;
    return (input);
}

t_token     *init_token(char **words)
{
    int     i;
    int     nb_words;
    t_token *token;

    i = 0;
    nb_words = 0;
    while (words[nb_words])
        nb_words++;
    token = (t_token *)malloc(sizeof(t_token) * (nb_words + 1));
    while (words[i])
    {
        token[i].word = words[i];
        token[i].is_expanded = 0;
        i++;
    }
    token[i].word = NULL;
    return (token);
}
