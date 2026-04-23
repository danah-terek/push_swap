/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:59:59 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 19:59:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (stack && *stack && (*stack)->next)
	{
		first = *stack;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
	}
}

void	sa(t_node **stack_a, t_ops *ops)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	if (ops)
		ops->sa++;
}

void	sb(t_node **stack_b, t_ops *ops)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	if (ops)
		ops->sb++;
}

void	ss(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	if (ops)
		ops->ss++;
}
