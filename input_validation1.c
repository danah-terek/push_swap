/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:01:38 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:01:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	duplicated(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				error_exit();
			j++;
		}
		i++;
	}
	return (1);
}

int	copy_input_split_to_array(char **arr, char **tmp, int j)
{
	int	n;

	n = 0;
	while (tmp[n])
	{
		arr[j] = ft_strdup(tmp[n]);
		if (!arr[j])
			return (-1);
		free(tmp[n]);
		j++;
		n++;
	}
	free(tmp);
	return (j);
}

char	**obt_arr(int argc, char **argv, int total_nums)
{
	int		i;
	int		j;
	char	**tmp;
	char	**arr;

	i = 0;
	j = 0;
	arr = malloc(sizeof(char *) * (total_nums + 1));
	if (!arr)
		error_exit();
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		j = copy_input_split_to_array(arr, tmp, j);
		if (j == -1)
			return (free_array(arr, j));
		i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**prepare_array(int ac, char **av, int *count)
{
	int		start;
	char	**array;

	start = count_flags(ac, av) + 1;
	*count = total_nums(ac - start, av + start);
	array = obt_arr(ac - start, av + start, *count);
	if (!array)
		error_exit();
	return (array);
}

long	is_validated(int ac, char **av)
{
	int		i;
	long	n;
	int		count;
	char	**array;

	i = 0;
	array = prepare_array(ac, av, &count);
	while (array[i])
	{
		if (is_number(array[i]))
		{
			n = ft_atoi(array[i]);
			if (n > 2147483647 || n < -2147483648)
				error_exit();
			i++;
		}
		else
			error_exit();
	}
	if (!duplicated(array))
		error_exit();
	free_array(array, count);
	return (1);
}
