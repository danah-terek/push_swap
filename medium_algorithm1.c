/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:01:10 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:01:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	push_chunk(t_node **a, t_node **b, t_range *range, t_ops *ops)
{
	int	pushed;
	int	chunk_size;

	pushed = 0;
	chunk_size = range->max - range->min + 1;
	while (pushed < chunk_size && *a)
	{
		if ((*a)->value >= range->min && (*a)->value <= range->max)
		{
			pb(a, b, ops);
			pushed++;
		}
		else
			ra(a, ops);
	}
}

void	chunks(t_node **stack_a, t_node **stack_b, int n, t_ops *ops)
{
	int		chunk_nb;
	int		chunk_size;
	t_range	range;

	chunk_nb = ft_sqrt(n);
	if (chunk_nb < 1)
		chunk_nb = 1;
	chunk_size = n / chunk_nb;
	range.min = 0;
	range.max = chunk_size - 1;
	while (range.min < n)
	{
		push_chunk(stack_a, stack_b, &range, ops);
		range.min += chunk_size;
		range.max += chunk_size;
		if (range.max >= n)
			range.max = n - 1;
	}
}

int	find_position_of_max_in_stackb(t_node *stack_b)
{
	int		max;
	t_node	*curr;
	int		index;

	max = find_max(stack_b);
	curr = stack_b;
	index = 0;
	while (curr != NULL)
	{
		if (curr->value == max)
			return (index);
		index++;
		curr = curr->next;
	}
	return (index);
}

void	push_back(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	int	max;
	int	pos;
	int	size;

	while (*stack_b != NULL)
	{
		max = find_max(*stack_b);
		pos = find_position_of_max_in_stackb(*stack_b);
		size = stack_size(*stack_b);
		if ((*stack_b)->value == max)
			pa(stack_a, stack_b, ops);
		else
		{
			if (pos > size / 2)
				rrb(stack_b, ops);
			else
				rb(stack_b, ops);
		}
	}
}

void	medium_algorithm(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	int	size;
	int	*arr;

	size = stack_size(*stack_a);
	arr = fill_array_with_values_from_stack(*stack_a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	replace_stack_values_with_index(stack_a, arr, size);
	free(arr);
	chunks(stack_a, stack_b, size, ops);
	push_back(stack_a, stack_b, ops);
}
