# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 23:25:09 by edelage           #+#    #+#              #
#    Updated: 2022/11/14 16:17:46 by edelage          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ***************************
#  Folders
# ***************************

OBJ_DIR =			.objs/

SRCS_DIR =			srcs/

INC_DIR =			includes/

LIBFT_DIR =			libft/

# ***************************
#  Files
# ***************************

ADD_FILE =			ft_print_char.c \
					ft_print_hexa.c \
					ft_print_int.c \
					ft_print_pointer.c \
					ft_print_str.c \
					ft_print_unsigned.c

SRCS =				$(addprefix $(SRCS_DIR), $(ADD_FILE)) \
					ft_printf.c

OBJS =				$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

HEADER =			$(INC_DIR)ft_printf.h

NAME =				libftprintf.a

LIBFT =				$(LIBFT_DIR)libft.a

# ***************************
#  Compilation
# ***************************

FLAGS =				-Wall -Wextra -Werror

# ***************************
#  Commands
# ***************************

AR_FLAGS =			rcs

RM =				rm -rf

MKDIR =				mkdir -p

MAKE =				make

# ***************************
#  Rules
# ***************************

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS) $(HEADER)
					cp $(LIBFT) $@
					$(AR) $(AR_FLAGS) $@ $(OBJS)

$(LIBFT):
					$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o:		%.c $(HEADER)
					$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
					$(MKDIR) $(addprefix $(OBJ_DIR), $(SRCS_DIR))

clean:
					$(MAKE) clean -C $(LIBFT_DIR)
					$(RM) $(OBJ_DIR)

fclean:
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(OBJ_DIR)
					$(RM) $(NAME)

re:					fclean all

.PHONY:			all clean fclean re
