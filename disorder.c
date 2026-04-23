/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:01:55 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:01:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

double	disorder(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	double	total_pairs;
	double	mistakes;

	total_pairs = 0;
	mistakes = 0;
	if (stack != NULL && stack->next != NULL)
	{
		i = stack;
		while (i != NULL)
		{
			j = i->next;
			while (j != NULL)
			{
				if (i->value > j->value)
					mistakes += 1;
				total_pairs += 1;
				j = j->next;
			}
			i = i->next;
		}
		return (mistakes / total_pairs);
	}
	return (0);
}
