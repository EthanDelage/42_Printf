/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:03:00 by ethan             #+#    #+#             */
/*   Updated: 2023/02/02 02:03:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <errno.h>

static int	ft_isdigit(char c);

int	ft_atoi(const char *str, size_t *index)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[*index]))
	{
		if ((result * 10 + (str[*index] - '0')) / 10 != result)
		{
			errno = EOVERFLOW;
			return (-1);
		}
		result = result * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (result);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
