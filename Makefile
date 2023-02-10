NAME		=		libftprintf.a

#######################
#	DIR
#######################

SRC_DIR		=		src/

INC_DIR		=		inc/

BUILD_DIR	=		.build/

#######################
#	FILES
#######################

SRCS		=		printf.c \
					utils/ft_atoi.c \
					utils/ft_memcpy.c \
					utils/ft_memset.c \
					utils/ft_strdup.c \
					lexer/lexer.c \
					lexer/lexer_conversion.c \
					lexer/lexer_utils.c \
					parser/parser.c \
					parser/conversion/conversion_char.c \
					parser/conversion/conversion_string.c \
					parser/conversion/conversion_pointer.c \
					parser/conversion/conversion_int.c \
					parser/conversion/conversion_unsigned.c \
					parser/conversion/conversion_hexa.c \
					exec/exec.c

OBJS		=		$(addprefix $(BUILD_DIR), $(SRCS:.c=.o))

DEPS		=		$(OBJS:.o=.d)

#######################
#	COMPILATIONS
#######################

CFLAGS		=		-Wall -Werror -Wextra

DFLAGS		=		-MMD -MP

IFLAGS		=		-I $(INC_DIR)

AR_FLAGS		=		rcs

#######################
#	RULES
#######################


all:				$(NAME)

-include			$(DEPS)

$(NAME):			$(OBJS)
					$(AR) $(AR_FLAGS) $@ $(OBJS)

$(BUILD_DIR)%.o:	$(SRC_DIR)%.c
					mkdir -p $(shell dirname $@)
					$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

clean:
					$(RM) $(OBJS) $(DEPS)

fclean:
					$(RM) $(OBJS) $(DEPS) $(NAME)

re:					fclean
					$(MAKE)

.PHONY:				all clean fclean re