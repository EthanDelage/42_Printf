/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:36:12 by edelage           #+#    #+#             */
/*   Updated: 2022/11/14 17:18:58 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	len_int(int nb)
{
	if (nb < -9)
		return (len_int(-(nb / 10)) + 2);
	else if (nb < 0)
		return (2);
	else if (nb > 9)
		return (len_int(nb / 10) + 1);
	else
		return (1);
}

void	fill_int(int nb, size_t len_nb, char *str)
{
	if (nb < 0)
	{
		str[0] = '-';
		str[len_nb - 1] = -(nb % 10) + '0';
		nb /= -10;
		len_nb -= 2;
		str++;
	}
	while (len_nb != 0)
	{
		str[len_nb - 1] = nb % 10 + '0';
		nb /= 10;
		len_nb--;
	}
}

int	ft_print_int(int nb)
{
	size_t	len_nb;
	char	*ascii_nb;

	len_nb = len_int(nb);
	ascii_nb = (char *) malloc(sizeof(char) * len_nb);
	if (ascii_nb == NULL)
		return (-1);
	fill_int(nb, len_nb, ascii_nb);
	write(1, ascii_nb, len_nb);
	free(ascii_nb);
	return ((int) len_nb);
}
