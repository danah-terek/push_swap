/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:00:41 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:00:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = temp->next;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
}

void	ra(t_node **stack_a, t_ops *ops)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	if (ops)
		ops->ra++;
}

void	rb(t_node **stack_b, t_ops *ops)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	if (ops)
		ops->rb++;
}

void	rr(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	if (ops)
		ops->rr++;
}
