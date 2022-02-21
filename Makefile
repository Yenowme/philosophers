# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:54:27 by jeong-yena        #+#    #+#              #
#    Updated: 2022/02/12 17:59:47 by jeong-yena       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= philo

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f

INCS_DIR				= ./include/
SRCS_DIR				= ./src/
INCS					= -I include

SRC						= main.c utils.c
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	@echo "\033[33m----Compiling lib----"
	$(CC) -o $(NAME) $(OBJS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR) -lpthread
	@echo "\n----Philosophers Compiled! 😻----"

all : $(NAME)

clean :
	$(RM) $(OBJS) a.out.dSYM

fclean : clean
	@echo "\n\033[31m----Delete everything 👌!----"
	$(RM) $(NAME) a.out.dSYM
	@echo "\n\033[31m----fclean done 👌!----\n"

re : fclean all

test :
	$(CC) -g -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR)

leak :
	$(CC) -g3 -fsanitize=address -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR)

norm :
	norminette $(SRCS) $(INCS_DIR)

PHONY	: all clean fclean re bonus
