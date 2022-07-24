#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

typedef struct	s_token
{
	char		*word;
	int			*is_expanded;
}				t_token;

typedef struct	s_input
{
	char		*string;
	t_token		*token;
	char		*path;
	int			type;
	int			fd_in;
	int			fd_out;
	int			stream_in;
	int			stream_out;
	int			is_last;
}				t_input;

enum	e_error
{
	NONE,		// 0
	SYNTAX_ERROR,	// 1
};

typedef struct	s_data
{
	enum e_error errors;

}				t_data;

t_data  data;

int				get_input();
char    		**ft_split_n_quotes(const char *stre, char c);





#endif
