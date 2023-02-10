/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:35:00 by ethan             #+#    #+#             */
/*   Updated: 2023/02/02 00:35:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	printf(const char *format, ...)
{
	int		count;
	t_param	*token_stack;
	va_list	ap;

	va_start(ap, format);
	token_stack = lexer(format);
	if (token_stack == NULL)
		return (-1);
	if (parser(token_stack, ap) == FAILURE)
	{
		token_clear(token_stack);
		return (-1);
	}
	va_end(ap);
	count = exec_write(token_stack, STDOUT_FILENO);
	token_clear(token_stack);
	return (count);
}
