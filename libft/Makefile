# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 14:38:11 by edelage           #+#    #+#              #
#    Updated: 2022/11/09 10:30:30 by edelage          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ***************************
#  Folders
# ***************************

OBJ_DIR =		.objs/


# ***************************
#  Files
# ***************************

SRCS =			ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

BONUS =			ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \

HEADER =		libft.h

OBJS =			$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJS_BONUS =	$(addprefix $(OBJ_DIR), $(BONUS:.c=.o))

NAME =			libft.a


# ***************************
# Compilation
# ***************************

FLAGS =			-Wall -Wextra -Werror


# ***************************
# Commands
# ***************************

AR_FLAGS =		rcs

MKDIR =			mkdir -p


# ***************************
# Rules
# ***************************

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				$(AR) $(AR_FLAGS) $@ $(OBJS)

bonus:			$(OBJ_DIR) $(OBJS) $(OBJS_BONUS)
				$(AR) $(AR_FLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJ_DIR)%.o:	%.c $(HEADER) Makefile
				$(CC) $(FLAGS) -I. -c $< -o $@

$(OBJ_DIR):
				$(MKDIR) $(OBJ_DIR)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				$(MAKE) all

.PHONY:			all clean fclean re bonus
