/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:01:01 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:01:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	*fill_array_with_values_from_stack(t_node *stack, int size)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack != NULL)
	{
		arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	replace_stack_values_with_index(t_node **stack, int *arr, int size)
{
	t_node	*curr;
	int		i;

	curr = *stack;
	while (curr != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == curr->value)
			{
				curr->value = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}
