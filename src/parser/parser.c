/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:41:01 by codespace         #+#    #+#             */
/*   Updated: 2023/02/05 15:42:21 by codespace        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

static int	conversion_router(t_param *head, va_list ap);
int			error(t_param *head);

int	parser(t_param *token_stack, va_list ap)
{
	t_param	*head;

	head = token_stack;
	while (token_stack)
	{
		if (token_stack->type == PERCENT)
		{
			token_stack->value = ft_strdup("%");
			if (errno)
				return (error(head));
		}
		if (token_stack->type != FORMAT
			&& token_stack->type != UNDEFINED)
		{
			if (conversion_router(token_stack, ap) == FAILURE)
				return (error(head));
		}
		token_stack = token_stack->next;
	}
	return (SUCCESS);
}

static int	conversion_router(t_param *head, va_list ap)
{
	int	return_value;

	if (head->type == CHAR)
		return_value = conversion_char(head, (unsigned char) va_arg(ap, int));
	else if (head->type == STRING)
		return_value = conversion_string(head, (char *) va_arg(ap, char *));
	else if (head->type == POINTER)
		return_value = conversion_pointer(head, va_arg(ap, size_t));
	else if (head->type == INTEGER)
		return_value = conversion_int(head, va_arg(ap, int));
	else if (head->type == UNSIGNED)
		return_value = conversion_unsigned(head, va_arg(ap, unsigned int));
	else if (head->type == HEXA_LOWER)
		return_value = conversion_hexa_low(head, va_arg(ap, unsigned int));
	else if (head->type == HEXA_UPPER)
		return_value = conversion_hexa_up(head, va_arg(ap, unsigned int));
	return (return_value);
}

int	error(t_param *head)
{
	token_clear(head);
	return (FAILURE);
}
