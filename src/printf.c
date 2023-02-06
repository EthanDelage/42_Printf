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
	count = 0;
	token_stack = lexer(format);
	if (token_stack == NULL)
		return (-1);
	va_end(ap);
	return (count);
}
