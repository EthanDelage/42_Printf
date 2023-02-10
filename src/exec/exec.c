/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 04:02:00 by ethan             #+#    #+#             */
/*   Updated: 2023/02/10 04:02:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	exec_write(t_param *head, int fd)
{
	int	count;

	count = 0;
	while (head)
	{
		if (write(fd, head->value, head->len_value) == -1)
			return (-1);
		count += head->len_value;
		head = head->next;
	}
	return (count);
}