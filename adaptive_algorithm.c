/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:02:25 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:02:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	adaptive_algorithm(t_node **stack_a, t_node **stack_b, t_ops *ops)
{
	double	dis;

	dis = disorder(*stack_a);
	if (dis < 0.2)
		simple_algorithm(stack_a, stack_b, ops);
	else if (dis < 0.5)
		medium_algorithm(stack_a, stack_b, ops);
	else
		complex_algorithm(stack_a, stack_b, ops);
}
