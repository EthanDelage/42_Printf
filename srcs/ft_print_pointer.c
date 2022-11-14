/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:19:57 by edelage           #+#    #+#             */
/*   Updated: 2022/11/14 16:04:58 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	len_ptr(size_t	ptr_value)
{
	if (ptr_value > 15)
		return (len_ptr(ptr_value / 16) + 1);
	else
		return (1);
}

void	fill_ptr(size_t ptr_value, size_t len, char *str)
{
	str[0] = '0';
	str[1] = 'x';
	str += 2;
	len -= 2;
	while (len != 0)
	{
		str[len - 1] = HEXA_LOWER[ptr_value % 16];
		ptr_value /= 16;
		len--;
	}
}

int	ft_print_pointer(void *ptr)
{
	size_t	ptr_value;
	size_t	len;
	char	*ascii_ptr;

	ptr_value = (size_t) ptr;
	len = len_ptr(ptr_value) + 2;
	ascii_ptr = (char *) malloc(sizeof(char) * len);
	if (ascii_ptr == NULL)
		return (-1);
	fill_ptr(ptr_value, len, ascii_ptr);
	write(1, ascii_ptr, len);
	free(ascii_ptr);
	return ((int) len);
}
