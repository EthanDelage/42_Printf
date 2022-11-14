/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:44:01 by edelage           #+#    #+#             */
/*   Updated: 2022/11/14 16:14:29 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	len_hexa(unsigned int nb)
{
	if (nb > 15)
		return (len_hexa(nb / 16) + 1);
	else
		return (1);
}

void	fill_hexa(unsigned int nb, size_t len_nb, char *hexa, char *base)
{
	while (len_nb != 0)
	{
		hexa[len_nb -1] = base[nb % 16];
		nb /= 16;
		len_nb--;
	}
}

int	ft_print_hexa_low(unsigned int nb)
{
	size_t	len_nb;
	char	*hexa;

	len_nb = len_hexa(nb);
	hexa = (char *) malloc(sizeof(char) * len_nb);
	if (hexa == NULL)
		return (-1);
	fill_hexa(nb, len_nb, hexa, HEXA_LOWER);
	write(1, hexa, len_nb);
	free(hexa);
	return ((int) len_nb);
}

int	ft_print_hexa_up(unsigned int nb)
{
	size_t	len_nb;
	char	*hexa;

	len_nb = len_hexa(nb);
	hexa = (char *) malloc(sizeof(char) * len_nb);
	if (hexa == NULL)
		return (-1);
	fill_hexa(nb, len_nb, hexa, HEXA_UPPER);
	write(1, hexa, len_nb);
	free(hexa);
	return ((int) len_nb);
}
