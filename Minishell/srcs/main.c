#include "../includes/minishell.h"


int main(int ac, char **av)
{
    data.errors = NONE;
    data.input = NULL;
    while(1)
    {
        if (!lexer())
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