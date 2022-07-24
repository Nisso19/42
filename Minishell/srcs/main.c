#include "../includes/minishell.h"


int main(int ac, char **av)
{
    t_input *input;

    data.errors = NONE;
    while(1)
    {
        if (!get_input(&input))
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