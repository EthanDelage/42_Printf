/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 03:43:00 by ethan             #+#    #+#             */
/*   Updated: 2023/02/10 03:43:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	index;

	index = 0;
	ptr = (char *) s;
	while (index < n)
	{
		ptr[index] = c;
		index++;
	}
	return (s);
}
