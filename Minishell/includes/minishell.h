#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../srcs/Libft/libft.h"

enum				e_error
{
	SYNTAX_ERROR,	// 0
	NONE,			// 1
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
	int				type;
	int				is_expanded;
}					t_token;

typedef struct		s_input
{
	char			*string;
	t_token			*token;
	char			*path;
	int				ftype;
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

//t_data				data;

/*
**	DEBUG
*/

int					input_debug(t_data *data);
int					tokens_debug(t_data *data);

/*
**	UTILS
*/

int					check_quotes(char c, int *quote);
int     			clean_free(void **ptr);
int     			buffer_flush(char buf[20], char **str, int *b);


/* 
**	LEXER
*/

int					check_type(const char *str);
int 				func_type(t_data *data);
int					set_type(t_data *data);
t_input				*init_input(char **pipelines);
t_token				*init_token(char **words);
int					lexer(t_data *data);
char				**ft_split_n_quotes(const char *stre, char *c, t_data *data);
int					split_check(char *str, int a, char *c);
int					split_word_count(char *s, char *c);
char				**split_final_check(char **tab, int quote, t_data *data);
char				**ft_redir_n_quotes(const char *stre, t_data *data);
char				**ft_tabjoin(char **tab1, char **tab2);

/*
**	PARSER
*/

int     			parameter_expansions(t_data *data);



#endif
