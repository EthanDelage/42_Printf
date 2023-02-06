/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:58:03 by edelage           #+#    #+#             */
/*   Updated: 2023/02/06 00:58:06 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <errno.h>

static size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *str)
{
	char			*new;
	size_t			index;
	const size_t	len = ft_strlen(str) + 1;

	new = (char *) malloc(sizeof(char) * len);
	if (errno)
		return (NULL);
	index = 0;
	while (index < len)
	{
		new[index] = str[index];
		index++;
	}
	return (new);
}

static size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
