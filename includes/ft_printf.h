/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:25:44 by edelage           #+#    #+#             */
/*   Updated: 2022/11/14 16:21:53 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# define HEXA_LOWER	"0123456789abcdef"
# define HEXA_UPPER	"0123456789ABCDEF"

int	ft_print_int(int nb);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_pointer(void *ptr);
int	ft_print_hexa_up(unsigned int nb);
int	ft_print_hexa_low(unsigned int nb);
int	ft_print_unsigned(unsigned int nb);
int	ft_printf(const char *format, ...);

#endif
