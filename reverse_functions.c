/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:00:47 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:00:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*before;
	t_node	*last;

	if (*stack && (*stack)->next)
	{
		before = *stack;
		last = before->next;
		while (last->next)
		{
			before = before->next;
			last = last->next;
		}
		last->next = *stack;
		before->next = NULL;
		*stack = last;
	}
}

void	rra(t_node **stack_a, t_ops *ops)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	if (ops)
		ops->rra++;
}

void	rrb(t_node **stack_b, t_ops *ops)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	if (ops)
		ops->rrb++;
}

void	rrr(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	if (ops)
		ops->rrr++;
}
