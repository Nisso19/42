#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "../srcs/Libft/libft.h"

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
}				t_input;

enum	e_error
{
	NONE,		// 0
	SYNTAX_ERROR,	// 1
};

typedef struct	s_data
{
	enum e_error	errors;
    t_input			*input;
}				t_data;

/*
**	GLOBAL SHELL VARIABLE
*/

t_data  data;

/*
**	DEBUG
*/
int				input_debug();
int     		tokens_debug();


/* 
**	LEXER
*/

t_input     	*init_input(char **pipelines);
t_token     	*init_token(t_input input, char **words);
int         	lexer();
char    		**ft_split_n_quotes(const char *stre, char *c);
int				split_check(char *str, int a, char *c);
int				split_check_quotes(char *str, int a, int *quote);
int				split_word_count(char *s, char *c);

/*
**	PARSER
*/




#endif
