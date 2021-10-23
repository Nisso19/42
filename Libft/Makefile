# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaainouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 13:56:27 by yaainouc          #+#    #+#              #
#    Updated: 2021/01/06 14:23:48 by yaainouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
      ft_strncpy.c \
      ft_lstnew.c \
	  ft_bzero.c \
	  ft_memcmp.c \
	  ft_strlcpy.c \
	  ft_strncmp.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_calloc.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_split.c \
	  ft_strcat.c \
	  ft_strcpy.c \

EXTRA = ft_lstclear.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJ = $(SRC:.c=.o) 

BNS = $(EXTRA:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@clang $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BNS)

fclean: clean
	@rm -f $(NAME)

bonus: $(OBJ) $(BNS)
	@ar rc $(NAME) $(OBJS) $(BNS)
	@ranlib $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
