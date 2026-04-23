/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:01:50 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:01:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_flag(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(str, "--bench") == 0)
		return (1);
	return (0);
}

int	has_bench(int argc, char **argv)
{
	if (argc > 1 && ft_strcmp(argv[1], "--bench") == 0)
		return (1);
	if (argc > 2 && ft_strcmp(argv[2], "--bench") == 0)
		return (1);
	return (0);
}

int	flags_checking(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= 2 && i < argc)
	{
		if (ft_strcmp("--simple", argv[i]) == 0)
			return (1);
		if (ft_strcmp("--medium", argv[i]) == 0)
			return (2);
		if (ft_strcmp("--complex", argv[i]) == 0)
			return (3);
		if (ft_strcmp("--adaptive", argv[i]) == 0)
			return (4);
		i++;
	}
	return (0);
}

int	count_flags(int argc, char **argv)
{
	int	count;

	count = 0;
	if (argc > 1 && is_flag(argv[1]))
		count++;
	if (argc > 2 && is_flag(argv[2]))
		count++;
	return (count);
}
