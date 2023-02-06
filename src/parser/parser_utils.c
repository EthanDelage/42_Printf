/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:03:53 by edelage           #+#    #+#             */
/*   Updated: 2023/02/06 01:03:54 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	is_no_flags(t_param *token)
{
	return (token->hashtag == false
		&& token->zero == false
		&& token->left_align == false
		&& token->space == false
		&& token->plus == false
		&& token->precision == false);
}
