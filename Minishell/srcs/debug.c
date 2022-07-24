#include "../includes/minishell.h"
int    input_debug()
{
    int     i;
    t_input *input;

    i = 0;
    input = data.input;
    printf("pipelines :\n");
    while(input[i].string)
    {
        printf("[%s] ", input[i].string);
        i++;
    }
    printf("\npipelines = %d\n", i + 1);
    return (1);
}

int     tokens_debug()
{
    int     i;
    int     y;
    t_input *input;
    t_token *token;

    i = 0;
    input = data.input;
    printf("tokens :\n");
    while(input[i].string)
    {
        y = -1;
        token = input[i].token;
        while (token[++y].word)
            printf("[%s] ", token[y].word);
        i++;
        printf("\n");
    }
    return (1);
}
