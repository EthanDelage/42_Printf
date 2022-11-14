/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:30:42 by edelage           #+#    #+#             */
/*   Updated: 2022/11/14 16:05:23 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	len_unsigned(unsigned int nb)
{
	if (nb > 9)
		return (len_unsigned(nb / 10) + 1);
	else
		return (1);
}

void	fill_unsigned(unsigned int nb, size_t len_nb, char *str)
{
	while (len_nb != 0)
	{
		str[len_nb - 1] = nb % 10 + '0';
		nb /= 10;
		len_nb--;
	}
}

int	ft_print_unsigned(unsigned int nb)
{
	size_t	len_nb;
	char	*ascii_nb;

	len_nb = len_unsigned(nb);
	ascii_nb = (char *) malloc(sizeof(char) * len_nb);
	if (ascii_nb == NULL)
		return (-1);
	fill_unsigned(nb, len_nb, ascii_nb);
	write(1, ascii_nb, len_nb);
	free(ascii_nb);
	return ((int) len_nb);
}
