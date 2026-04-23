/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:02:19 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:02:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putfloat_fd(double n, int fd)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)n;
	decimal_part = (int)((n - integer_part) * 100);
	if (decimal_part < 0)
		decimal_part = -decimal_part;
	ft_putnbr_fd(integer_part, fd);
	write(fd, ".", 1);
	if (decimal_part < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(decimal_part, fd);
}
