# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 14:10:46 by zdasser           #+#    #+#              #
#    Updated: 2022/05/26 14:10:49 by zdasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c error_handling.c minishell_utils.c redirections.c execution.c\

CC = @gcc -g -lreadline -L /Users/zdasser/.brew/opt/readline/lib -I/Users/zdasser/.brew/opt/readline/include

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

RM = @rm -f

all:		$(NAME)

$(NAME):
			@cd libft && make && make bonus && cd ..
			$(CC) $(CFLAGS) $(LIBFT) $(SRC) -o $(NAME)
			@echo "\033[0;32m®minishell CREATED 🐲\033[0m"

t:
			@./$(NAME)
clean:
			@cd libft && make clean && cd ..

fclean: 	
			@cd libft && make fclean && cd ..
			$(RM) $(NAME)
			@echo "\033[0;31mminishell DELETED 🗑"

re:			fclean all