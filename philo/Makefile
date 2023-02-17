# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 22:18:31 by znichola          #+#    #+#              #
#    Updated: 2023/02/17 01:50:11 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET=\033[0m
BLUE=\033[34m
RED=\033[31m
GREEN=\033[32m
MAGENTA=\033[35m
YELLOW=\033[33m
GREY=\033[90m
JMP_UP=\033[1A
JMP_STRT=\033[100D

NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra
# CFLAGS	+=	-Werror
RM		=	rm -r

# If DEBUG env variable is set, compile with debugging symbols
# and the compiler's address sanitizer
ifdef DEBUG
	CFLAGS	+=	-g3 -fsanitize=address
endif

INC_PATH	=	includes/
SRC_PATH	=	srcs/
OBJ_PATH	=	objs/

UTILS		=	debug print safe_atoi
PHILO		=	input philo init_philo

UTILS		:=	$(addprefix utils/,	$(UTILS))
PHILO		:=	$(addprefix philo/,	$(PHILO))


FILES		=	main $(UTILS) $(PHILO)

SRCS		=	$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES)))
INCS		=	$(addprefix -I, $(INC_PATH))

all : $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(@D)
	@printf "$(GREEN) compiling ..$(GREY) $@$ $(RESET)$(JMP_STRT)"
	@$(CC) $(CFLAGS) -c $(INCS) -o $@ $<
#	@printf "$(JMP_UP)$(JMP_UP)"

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INCS) -o $@

bonus :
	@echo "no bonus :("

clean :
	@$(RM) $(OBJS) 2>/dev/null && printf "$(BLUE).. removed objects\n$(RESET)" || true

fclean : clean
	@$(RM) $(NAME) 2>/dev/null && printf "$(BLUE).. removed $(NAME) binary\n$(RESET)" || true

re : fclean all

.PHONY : all re clean fclean bonus

# .SILENT:
