/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_into_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:01:44 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:01:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_back(t_node **stack, t_node *new)
{
	t_node	*tmp;

	if (!*stack)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	append_node(t_node **stack, t_node **current, int val)
{
	t_node	*new;

	new = new_node(val);
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		*current = new;
	}
	else
	{
		(*current)->next = new;
		*current = new;
	}
}

t_node	*input_to_stack(char **arr)
{
	t_node	*stack_a;
	t_node	*current;
	int		i;

	stack_a = NULL;
	stack_a = NULL;
	i = 0;
	while (arr[i])
	{
		append_node(&stack_a, &current, ft_atoi(arr[i]));
		i++;
	}
	return (stack_a);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
