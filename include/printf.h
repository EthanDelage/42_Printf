/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:33:00 by ethan             #+#    #+#             */
/*   Updated: 2023/02/02 00:33:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>

enum
{
	SUCCESS	=	0,
	FAILURE	=	1,
};

typedef enum e_type
{
	FORMAT,
	CHAR,
	STRING,
	POINTER,
	INTEGER,
	UNSIGNED,
	HEXA_LOWER,
	HEXA_UPPER,
	PERCENT,
	UNDEFINED,
}	t_type;

typedef struct s_param
{
	t_type			type;
	char			*value;
	bool			hashtag;
	bool			zero;
	bool			left_align;
	bool			space;
	bool			plus;
	int				width;
	bool			precision;
	int				length;
	struct s_param	*next;
}	t_param;

int		ft_printf(const char *format, ...);

/* --------------- CONVERSION FUNCTIONS --------------- */

int 	conversion_char(t_param *token, unsigned char c);

/* --------------- LEXER FUNCTIONS --------------- */

t_param	*lexer(const char *format);
int		lexer_conversion(const char *format,
			t_param **token_stack, size_t *index);

/* --------------- TOKEN FUNCTIONS --------------- */

t_param	*token_new(void);
void	token_add_front(t_param **head, t_param *token);
void	token_reverse_stack(t_param **head);
void	token_clear(t_param *head);

/* --------------- UTILS FUNCTIONS --------------- */

int 	is_no_flags(t_param *token);
char    *ft_strdup(const char *str);
int		ft_atoi(const char *str, size_t *index);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
