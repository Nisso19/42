#include "../includes/minishell.h"
int    input_debug(t_data *data)
{
    int     i;
    t_input *input;

    i = 0;
    input = data->input;
    printf("\npipelines :");
    while(input[i].string)
    {
        printf(" [%s] ", input[i].string);
        i++;
    }
    printf("|| Nombre de pipelines = %d\n", i);
    printf("---------------------\n");
    return (1);
}

int     tokens_debug(t_data *data)
{
    int     i;
    int     y;
    t_input *input;
    t_token *token;

    i = 0;
    input = data->input;
    if(data->input->ftype == 0)
        printf("Func type[BUILT IN]]\n");
    else if(data->input->ftype == 1)
        printf("Func type[EXECUTABLE]\n");
    printf("---------------------\n");
    printf("Tokens : ");
    while(input[i].string)
    {
        y = -1;
        token = input[i].token;
        while (token[++y].word)
        {
            printf("[%s]=", token[y].word);
            if(token[y].type  == 0)
            printf("Word  ");
            if(token[y].type  == 1)
            printf("Redir  ");
            if(token[y].type  == 2)
            printf("AfterRedir  ");
        }

        i++;
        printf("\n");
    }
    return (1);
}
