#include "../includes/minishell.h"

int		set_type(t_data *data)
{
	int     i;
    int     flag;
    int     u;
    t_token *token;
    t_input *input;

    u = 0;
    i = 0;
    flag = 0;
    input = data->input;
    token = input[i].token;  
    while (token[i].word)
    {
        if(token[i].word[u] == '<' || token[i].word[u] == '>')
        {
                u++;
                if (token[i].word[u] == token[i].word[u - 1])
                    u++;
		        if (token[i].word[u] == '<' || token[i].word[u] == '>' || flag == 1)
                {
                    data->errors = 0;
                    return(0);
                }
                token[i].type = 1;
                flag = 1;
                u = 0;
        }
        else if(flag == 1)
        {
            token[i].type = 2;
            flag = 0;
        }
        else
            token[i].type = 0;
        i++;
	}
    if(flag == 1)
    {
        data->errors = 0;
        return(0);
    }
    func_type(data);
    return (1);
}

int func_type(t_data *data)
{
    int i;
    t_input *input;
    t_token *token; 
    
    i = 0;
    input = data->input;
    token = input[i].token; 
    while (token[i].word)
    {
        if(token[i].type == 0)
        {
            if(check_type(token[i].word) == 1)
                data->input->ftype = 1;
            else if(check_type(token[i].word) == 0)
                data->input->ftype = 0;
            return(0);
        }
        i++;
    }
    return(0);
}

int check_type(const char *str)
{
    int i;
    const char *str2[4];

    i = 0;
    str2[0] = "cd";
    str2[1] = "ls";
    str2[2] = "exit";
    str2[3] = NULL;
    while(str2[i] != NULL)
    {
    if (ft_strncmp(str2[i], str, 4) == 0)
        return(0);
    i++;
    }
    return(1);
}