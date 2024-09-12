# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoshi <aoshi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 04:18:30 by yoaoki            #+#    #+#              #
#    Updated: 2024/09/13 04:30:40 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = project
NAME_CLIENT = client
NAME_SERVER = server
NAMEBC = client_bonus
NAMEBS = server_bonus
INCLUDE = include/
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRC_CL_FILES = client
SRC_SV_FILES = server
SRCBC_FILES = client_bonus
SRCBS_FILES = server_bonus

SRC_CL = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_CL_FILES)))
OBJ_CL = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_CL_FILES)))

SRC_SV = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_SV_FILES)))
OBJ_SV = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_SV_FILES)))

SRCBC =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBC_FILES)))
OBJBC =	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBC_FILES)))

SRCBS =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBS_FILES)))
OBJBS =	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBS_FILES)))

OBJF = .chache_exists

start:
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@make all

all:		$(NAME)

$(NAME): $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CL) $(OBJF)
	$(CC) $(CFLAGS) $(OBJ_CL) -I $(INCLUDE) libft.a -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SV) $(OBJF)
	$(CC) $(CFLAGS) $(OBJ_SV) -I $(INCLUDE) libft.a -o $(NAME_SERVER)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(OBJF)
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)
	touch $(OBJF)

bonus:
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	make allbonus

allbonus:	$(NAMEBC) $(NAMEBS)

$(NAMEBC):	$(OBJBC) $(OBJF)
			@$(CC) $(FLAGS) $(OBJBC) -I $(INCLUDE) libft.a -o $(NAMEBC)

$(NAMEBS):	$(OBJBS) $(OBJF)
			@$(CC) $(FLAGS) $(OBJBS) -I $(INCLUDE) libft.a -o $(NAMEBS)

clean:
			$(RM) -r $(OBJ_DIR)
			$(RM) $(OBJF)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAMEBC) $(NAMEBS)
			$(RM) $(LIBFT)/libft.a
			$(RM) libft.a

re:			fclean start all

.PHONY:		start all clean fclean re bonus
