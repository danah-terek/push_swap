/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:00:54 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:00:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	pa(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	t_node	*temp;

	if ((*stack_b) != NULL)
	{
		temp = *stack_b;
		(*stack_b) = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
		write(1, "pa\n", 3);
		if (ops)
			ops->pa++;
	}
}

void	pb(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	t_node	*temp;

	if ((*stack_a) != NULL)
	{
		temp = *stack_a;
		(*stack_a) = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
		write(1, "pb\n", 3);
		if (ops)
			ops->pb++;
	}
}
