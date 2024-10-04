# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaainouc <yaainouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:47:59 by yaainouc          #+#    #+#              #
#    Updated: 2024/10/04 18:31:25 by yaainouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *************************************************************************** #
CLEAR_SCREEN = \033[2J\033[1;1H
RESET_C	= \033[0m
BOLD	= \033[1m
BLACK	= \033[30m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
MAGENTA	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m
DEFAUT	= \033[39m
SUR_GREEN = \033[42m 

# *************************************************************************** #

NAME		= PmergeMe
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD
RM			= rm -rf

OBJDIR = .objs

FILES		= PmergeMe main

SRC			= $(FILES:=.cpp)
OBJS		= $(addprefix $(OBJDIR)/, $(FILES:=.o))
DEP			:= ${OBJS:.o=.d}
HEADER		= PmergeMe.hpp

.PHONY: all clean fclean re bonus norm

all: clear $(NAME)

-include $(DEP)
$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "${CLEAR_SCREEN}"
	@echo "\t${GREEN}---\t$@ 🗹\t---${RESET_C}"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "${CYAN}Generating ${NAME}'s objects.... ${RESET_C}" "${YELLOW}$@"

clear			:
	echo "${CLEAR_SCREEN}"

clean:
	@$(RM) $(OBJDIR) $(OBJS)
	@echo "${RED}\t---\t${NAME} clean\t---${RESET_C}"

fclean: clean
	@$(RM) $(NAME)
	@echo "${RED}\t---\t${NAME} fclean\t---${RESET_C}"

re: clear fclean all