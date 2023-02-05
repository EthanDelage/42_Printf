/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:25:00 by ethan             #+#    #+#             */
/*   Updated: 2023/02/02 01:25:00 by ethan            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

static	t_param	*token_free(t_param *token);

t_param	*token_new(void)
{
	t_param	*new_token;

	new_token = (t_param *) malloc(sizeof(t_param));
	if (errno)
		return (NULL);
	new_token->value = NULL;
	new_token->hashtag = false;
	new_token->zero = false;
	new_token->left_align = false;
	new_token->space = false;
	new_token->plus = false;
	new_token->precision = false;
	new_token->next = NULL;
	return (new_token);
}

void	token_add_front(t_param **head, t_param *token)
{
	token->next = *head;
	*head = token;
}

void	token_reverse_stack(t_param **head)
{
	t_param	*current;
	t_param	*previous;
	t_param	*next;

	current = *head;
	previous = NULL;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}

void	token_clear(t_param *head)
{
	while (head)
		head = token_free(head);
}

static	t_param	*token_free(t_param *token)
{
	t_param	*next;

	next = token->next;
	free(token);
	if (token->value)
		free(token->value);
	return (next);
}
