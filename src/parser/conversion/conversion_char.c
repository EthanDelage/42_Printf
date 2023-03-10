/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:01:49 by edelage           #+#    #+#             */
/*   Updated: 2023/02/06 01:01:51 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	conversion_char(t_param *token, unsigned char c)
{
	token->value = (char *) malloc(sizeof(char));
	if (errno)
	{
		token->value = NULL;
		return (FAILURE);
	}
	token->value[0] = c;
	token->len_value = 1;
	return (SUCCESS);
}
