/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:10:00 by ethan             #+#    #+#             */
/*   Updated: 2023/02/02 02:10:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

static int		is_flag(char c);
static void		flag_change_state(t_param *param, char flag);
static int		lexer_precision(const char *format, size_t *index,
					t_param *param);
static t_type	lexer_get_type(char c, t_param *param);

int	lexer_conversion(const char *format, t_param **token_stack, size_t *index)
{
	t_param	*param;

	param = token_new();
	if (errno)
	{
		token_clear(*token_stack);
		return (FAILURE);
	}
	(*index)++;
	while (is_flag(format[*index]))
	{
		flag_change_state(param, format[*index]);
		(*index)++;
	}
	param->width = ft_atoi(format, index);
	if (lexer_precision(format, index, param) == FAILURE
		|| lexer_get_type(format[*index], param) == UNDEFINED)
	{
		token_clear(*token_stack);
		return (FAILURE);
	}
	(*index)++;
	token_add_front(token_stack, param);
	return (SUCCESS);
}

static int	is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+');
}

static void	flag_change_state(t_param *param, char flag)
{
	if (flag == '#')
		param->hashtag = true;
	else if (flag == '0')
		param->zero = true;
	else if (flag == '-')
		param->left_align = true;
	else if (flag == ' ')
		param->space = true;
	else if (flag == '+')
		param->plus = true;
}

static int	lexer_precision(const char *format, size_t *index, t_param *param)
{
	if (format[*index] == '.')
	{
		param->precision = true;
		(*index)++;
		if (format[*index] == '.')
			return (FAILURE);
		param->length = ft_atoi(format, index);
	}
	return (SUCCESS);
}

static t_type	lexer_get_type(char c, t_param *param)
{
	if (c == 'c')
		param->type = CHAR;
	else if (c == 's')
		param->type = STRING;
	else if (c == 'p')
		param->type = POINTER;
	else if (c == 'd' || c == 'i')
		param->type = INTEGER;
	else if (c == 'u')
		param->type = UNSIGNED;
	else if (c == 'x')
		param->type = HEXA_LOWER;
	else if (c == 'X')
		param->type = HEXA_UPPER;
	else if (c == '%')
		param->type = PERCENT;
	else
		param->type = UNDEFINED;
	return (param->type);
}
