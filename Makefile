# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 04:18:30 by yoaoki            #+#    #+#              #
#    Updated: 2024/08/02 19:21:54 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
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

SRC_CL = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_CL_FILES)))
OBJ_CL = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_CL_FILES)))

SRC_SV = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_SV_FILES)))
OBJ_SV = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_SV_FILES)))

OBJF = .chache_exists

start:
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@make all

all:		$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CL) $(OBJF)
	$(CC) $(CFLAGS) $(OBJ_CL) -I $(INCLUDE) libft.a -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SV) $(OBJF)
	$(CC) $(CFLAGS) $(OBJ_SV) -I $(INCLUDE) libft.a -o $(NAME_SERVER)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(OBJF)
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)
	touch $(OBJF)

clean:
			$(RM) -r $(OBJ_DIR)
			$(RM) $(OBJF)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME_CLIENT) $(NAME_SERVER)
			$(RM) $(LIBFT)/libft.a
			$(RM) libft.a

re:			fclean start all

.PHONY:		start all clean fclean re
