/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:10:00 by ethan             #+#    #+#             */
/*   Updated: 2023/02/02 01:10:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

static int	add_format_part(const char *format, size_t start, size_t end,
				t_param **token_stack);

t_param	*lexer(const char *format)
{
	size_t	start;
	size_t	index;
	t_param	*token_stack;

	index = 0;
	start = 0;
	token_stack = NULL;
	while (format[index])
	{
		if (format[index] == '%')
		{
			if (add_format_part(format, start, index, &token_stack) == FAILURE)
				return (NULL);
			if (lexer_conversion(format, &token_stack, &index) == FAILURE)
				return (NULL);
			start = index;
		}
		index++;
	}
	if (add_format_part(format, start, index, &token_stack) == FAILURE)
		return (NULL);
	token_reverse_stack(&token_stack);
	return (token_stack);
}

static int	add_format_part(const char *format, size_t start, size_t end,
				t_param **token_stack)
{
	t_param	*new_token;
	char	*str;

	if (start == end)
		return (SUCCESS);
	str = (char *) malloc(sizeof(char) * (end - start + 1));
	if (errno)
	{
		token_clear(*token_stack);
		return (FAILURE);
	}
	ft_memcpy((void *) str, (void *) format + start, end - start);
	str[end - start] = '\0';
	new_token = token_new();
	if (errno)
	{
		token_clear(*token_stack);
		free(str);
		return (FAILURE);
	}
	new_token->type = FORMAT;
	new_token->value = (void *) str;
	token_add_front(token_stack, new_token);
	return (SUCCESS);
}