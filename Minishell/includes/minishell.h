#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "get_next_line.h"
#include "../srcs/Libft/libft.h"

enum				e_error
{
	NONE,			// 0
	SYNTAX_ERROR,	// 1
};

enum				e_redir
{
	INPUT,			// 0
	OUTPUT,			// 1
	HEREDOC,		// 2
	APPEND,			// 3
};

typedef struct		s_redir
{
	char			*file;
	enum e_redir	type;
}					t_redir;

typedef struct		s_token
{
	char			*word;
	int				is_expanded;
}					t_token;

typedef struct		s_input
{
	char			*string;
	t_token			*token;
	char			*path;
	int				type;
	int				fd_in;
	int				fd_out;
	int				stream_in;
	int				stream_out;
}					t_input;

typedef struct		s_data
{
	enum e_error	errors;
	char			**env;
    t_input			*input;
}					t_data;

/*
**	GLOBAL SHELL VARIABLE
*/

t_data				data;

/*
**	DEBUG
*/

int					input_debug();
int					tokens_debug();

/*
**	UTILS
*/

int					check_quotes(char c, int *quote);
int     			clean_free(void **ptr);
int     			buffer_flush(char buf[20], char **str, int *b);


/* 
**	LEXER
*/

t_input				*init_input(char **pipelines);
t_token				*init_token(t_input input, char **words);
int					lexer();
char				**ft_split_n_quotes(const char *stre, char *c);
int					split_check(char *str, int a, char *c);
int					split_word_count(char *s, char *c);
char				**split_final_check(char **tab, int quote);
char				**ft_redir_n_quotes(const char *stre);
char				**ft_tabjoin(char **tab1, char **tab2);

/*
**	PARSER
*/

int     			parameter_expansions();



#endif
