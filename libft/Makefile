# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 04:18:30 by yoaoki            #+#    #+#              #
#    Updated: 2024/05/15 05:08:12 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = include/
SRC_DIR = src/
OBJ_DIR = src/
CC = cc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs
ECHO = echo -e

SRC_LIBFT = ft_isalpha ft_isdigit ft_isalnum ft_isascii \
			ft_isprint ft_strlen ft_memset ft_toupper ft_tolower\
			ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat \
			ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
			ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr \
			ft_strjoin ft_strtrim ft_itoa ft_split ft_strmapi ft_striteri\
			ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
			ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast\
			ft_lstadd_back ft_lstdelone ft_lstclear\
			ft_lstiter ft_lstmap

SRC_PRINTF = ft_printf ft_put_convert ft_print_char ft_print_str\
			 ft_print_ptr ft_print_percent ft_print_int ft_print_uint\
			 ft_print_hex ft_puthex_fd ft_putuint_fd ft_numlen ft_putptr_fd\

SRC_GNL = get_next_line_bonus get_next_line_utils_bonus

LIBFT_DIR = o_libft/
PRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/

SRC_FILES += $(addprefix $(LIBFT_DIR), $(SRC_LIBFT))
SRC_FILES += $(addprefix $(PRINTF_DIR), $(SRC_PRINTF))
SRC_FILES += $(addprefix $(GNL_DIR), $(SRC_GNL))

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			$(RM)  $(OBJ_DIR)/$(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
