# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 22:18:31 by znichola          #+#    #+#              #
#    Updated: 2022/12/29 16:55:50 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

FILES	=	main debug2 input philo #safe_atoi

SRC		=	$(addsuffix .c, $(FILES))
OBJ		= 	$(SRC:.c=.o)

INCLUDE	=	philo.h

INC_PAR	=	$(addprefix -I, $(INCLUDE))


CC 		=	gcc
# CFLAGS	=	-Wall -Werror -Wextra
CFLAGS	=	-g -pthread
# CFLAGS	=	-S
RM		=	rm -f

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(@)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC_PAR)

bonus :
	@echo "no bonus :("

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all re clean fclean bonus

# .SILENT:
