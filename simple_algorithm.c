/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:00:33 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:00:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	sorting_three(t_node **stack, t_ops *ops)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack, ops);
	else if (a > b && b > c)
	{
		sa(stack, ops);
		rra(stack, ops);
	}
	else if (a < b && b > c && a > c)
		rra(stack, ops);
	else if (a < b && b > c && a < c)
	{
		sa(stack, ops);
		ra(stack, ops);
	}
	else if (a > b && b < c && a > c)
		ra(stack, ops);
}

int	find_position_of_min(t_node *stack)
{
	int		min;
	t_node	*curr;
	int		index;

	min = find_min(stack);
	curr = stack;
	index = 0;
	while (curr != NULL)
	{
		if (curr->value == min)
			return (index);
		index++;
		curr = curr->next;
	}
	return (index);
}

void	rotate_to_min(t_node **stack, t_ops *ops)
{
	int	pos;
	int	size;
	int	min;

	min = find_min(*stack);
	pos = find_position_of_min(*stack);
	size = stack_size(*stack);
	while ((*stack)->value != min)
	{
		if (pos >= size / 2)
			rra(stack, ops);
		else
			ra(stack, ops);
	}
}

void	simple_algorithm(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	while ((*stack_a) != NULL)
	{
		rotate_to_min(stack_a, ops);
		pb(stack_a, stack_b, ops);
	}
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b, ops);
}
