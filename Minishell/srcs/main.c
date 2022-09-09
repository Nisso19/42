#include "../includes/minishell.h"


int main(int ac, char **av)
{
    extern char    **environ;
    t_data data;
    (void)ac;
    (void)av;
    data.errors = NONE;
    data.env = environ;
    data.input = NULL;
    while(1)
    {
        if (!lexer(&data))
        {
            if (data.errors == NONE) // si NONE -> erreur de malloc donc on exit
                return (0);
        }
        else
        {
            // exec ici
        }
    }
    return (0);
}