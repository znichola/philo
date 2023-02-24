# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 22:18:31 by znichola          #+#    #+#              #
#    Updated: 2023/02/24 16:39:13 by znichola         ###   ########.fr        #
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

CONTROLLER	=	cleanup wait launch
PHILO		=	input philo init_philo
STRUCTS		=	t_philo
UTILS		=	debug print safe_atoi

CONTROLLER		:=	$(addprefix controller/, $(CONTROLLER))
PHILO		:=	$(addprefix philo/, $(PHILO))
STRUCTS		:=	$(addprefix structs/, $(STRUCTS))
UTILS		:=	$(addprefix utils/, $(UTILS))


FILES		=	main $(CONTROLLER) $(PHILO) $(STRUCTS) $(UTILS)

SRCS		=	$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES)))
INCS		=	$(addprefix -I, $(INC_PATH))

all : format_compiling $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(@D)
#	@printf "$(GREEN) compiling ..$(GREY) $@$ $(RESET)$(JMP_STRT)"
	@printf "$(JMP_UP)\e[14C$(GREY) $@$ $(RESET)\n"
	@$(CC) $(CFLAGS) -c $(INCS) -o $@ $<
#	@printf "$(JMP_UP)$(JMP_UP)"

$(NAME) : $(OBJS)
	@printf "$(YELLOW).. linking$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -pthread $(INCS) -o $@

bonus :
	@echo "no bonus :("

clean :
	@$(RM) $(OBJS) 2>/dev/null && printf "$(BLUE).. removed objects\n$(RESET)" || true

fclean : clean
	@$(RM) $(NAME) 2>/dev/null && printf "$(BLUE).. removed $(NAME) binary\n$(RESET)" || true

re : fclean all

format_compiling :
	@printf "$(GREEN)   compiling : $(RESET)\n"


.PHONY : all re clean fclean bonus

# .SILENT:

MANDETORY_FUNCS	=	memset                \
					printf                \
					malloc                \
					free                  \
					write                 \
					usleep                \
					gettimeofday          \
					pthread_create        \
					pthread_detach        \
					pthread_join          \
					pthread_mutex_init    \
					pthread_mutex_destroy \
					pthread_mutex_lock    \
					pthread_mutex_unlock  \

BONUS_FUNCS		=	memset                \
					printf                \
					malloc                \
					free                  \
					write                 \
					fork                  \
					kill                  \
					exit                  \
					pthread_create        \
					pthread_detach        \
					pthread_join          \
					usleep                \
					gettimeofday          \
					waitpid               \
					sem_open              \
					sem_close             \
					sem_post              \
					sem_wait              \
					sem_unlink            \
