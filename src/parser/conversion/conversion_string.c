/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:02:38 by edelage           #+#    #+#             */
/*   Updated: 2023/02/06 01:02:40 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

static int	conversion_string_null(t_param *token);
static void	conversion_string_fill(char *value, int str, t_param *token);
static void	conversion_string_fill_space(int len_str, t_param *token);
static void	conversion_string_fill_str(char *str, int len_str,
				t_param *token);

int	conversion_string(t_param *token, char *str)
{
	if (str == NULL)
	{
		if (conversion_string_null(token) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	conversion_string_null(t_param *token)
{
	const int	len_str = SIZE_NULL_STR;
	int			total_len;

	total_len = len_str;
	if (token->precision == true)
	{
		if (token->length < 6)
			total_len = 0;
		else
			total_len = token->length;
	}
	if (token->width != -1 && token->width > total_len)
		total_len = token->width;
	token->value = (char *) malloc(sizeof(char) * total_len);
	if (errno)
		return (FAILURE);
	token->len_value = total_len;
	if (token->precision == false
		|| (token->precision == true && token->length >= 6))
		conversion_string_fill("(null)", SIZE_NULL_STR, token);
	else
		conversion_string_fill("", 0, token);
	return (SUCCESS);
}

static void	conversion_string_fill(char *str, int len_str, t_param *token)
{
	if (token->precision == true && token->length < len_str)
		len_str = token->length;
	conversion_string_fill_str(str, len_str, token);
	if (token->width > len_str)
		conversion_string_fill_space(len_str, token);
}

static void	conversion_string_fill_str(char *str, int len_str,
				t_param *token)
{
	void	*dest;

	dest = token->value;
	if (token->width != -1 && token->left_align == false)
		ft_memcpy(dest + token->len_value - len_str, (void *) str, len_str);
	else
		ft_memcpy(dest, (void *) str, len_str);
}

static void	conversion_string_fill_space(int len_str, t_param *token)
{
	void	*dest;

	dest = token->value;
	if (token->left_align == true && len_str < token->width)
		ft_memset(dest + len_str, ' ', token->width - len_str);
	else
		ft_memset(dest, ' ', token->width - len_str);
}
