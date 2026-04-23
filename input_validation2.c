/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:01:30 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	total_nums(int argc, char **argv)
{
	int	total_nums;
	int	i;

	total_nums = 0;
	i = 0;
	while (i < argc)
	{
		total_nums += ft_count_words(argv[i], ' ');
		i++;
	}
	return (total_nums);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	count;
	int		minus;

	minus = 0;
	i = 0;
	count = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		count = (count * 10) + (nptr[i] - '0');
		i++;
	}
	if (minus == 1)
		return (-count);
	return (count);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i])
	{
		i++;
	}
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		error_exit();
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		error_exit();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit();
		i++;
	}
	return (1);
}
