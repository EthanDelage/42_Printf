/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:48:12 by edelage           #+#    #+#             */
/*   Updated: 2022/11/14 17:50:55 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_convert(va_list ap, char type)
{
	int	bytes_write;

	bytes_write = -1;
	if (type == 'c')
		bytes_write = ft_print_char((char) va_arg(ap, int));
	else if (type == 's')
		bytes_write = ft_print_str(va_arg(ap, char *));
	else if (type == 'p')
		bytes_write = ft_print_pointer(va_arg(ap, void *));
	else if (type == 'd' || type == 'i')
		bytes_write = ft_print_int(va_arg(ap, int));
	else if (type == 'u')
		bytes_write = ft_print_unsigned(va_arg(ap, unsigned int));
	else if (type == 'x')
		bytes_write = ft_print_hexa_low(va_arg(ap, unsigned int));
	else if (type == 'X')
		bytes_write = ft_print_hexa_up(va_arg(ap, unsigned int));
	else if (type == '%')
		bytes_write = ft_print_char('%');
	return (bytes_write);
}

int	ft_write_format(const char *format, va_list ap)
{
	int		total_bytes;
	int		bytes_add;
	size_t	index;

	index = 0;
	total_bytes = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			bytes_add = ft_convert(ap, format[index + 1]);
			if (bytes_add == -1)
				return (-1);
			total_bytes += bytes_add;
			index += 2;
		}
		else
		{
			write(1, format + index, 1);
			total_bytes += 1;
			index++;
		}
	}
	return (total_bytes);
}

int	ft_printf(const char *format, ...)
{
	int		total_bytes;
	va_list	ap;

	va_start(ap, format);
	total_bytes = ft_write_format(format, ap);
	va_end(ap);
	return (total_bytes);
}
