/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:02:01 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:02:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	one_radix_pass(t_node **s_a, t_node **s_b, t_range *range, t_ops *ops)
{
	int	i;
	int	value;

	i = 0;
	while (i < range->size)
	{
		value = (*s_a)->value;
		if (((value >> range->bit) & 1) == 0)
			pb(s_a, s_b, ops);
		else
			ra(s_a, ops);
		i++;
	}
}

void	push_b_back_to_a(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	while (*stack_b != NULL)
		pa(stack_a, stack_b, ops);
}

void	index_stack(t_node **stack_a)
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
}

void	complex_algorithm(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	int		max_bits;
	t_range	range;

	index_stack(stack_a);
	range.size = stack_size(*stack_a);
	max_bits = get_max_bits(range.size - 1);
	range.bit = 0;
	while (range.bit < max_bits)
	{
		one_radix_pass(stack_a, stack_b, &range, ops);
		push_b_back_to_a(stack_a, stack_b, ops);
		range.bit++;
	}
}
