/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:02:09 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:02:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_strategy(double dis, int flag)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (flag == 1)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Medium / O(n*sqrt(n))\n", 2);
	else if (flag == 3)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (dis < 0.2)
			ft_putstr_fd("O(n)\n", 2);
		else if (dis < 0.5)
			ft_putstr_fd("O(n*sqrt(n))\n", 2);
		else
			ft_putstr_fd("O(n log n)\n", 2);
	}
}

void	ops_print(t_ops *ops)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(ops->sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(ops->ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(ops->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(ops->pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ops->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(ops->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(ops->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(ops->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(ops->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(ops->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	bench_print(double dis, t_ops *ops, int flag)
{
	int	total;

	total = ops->sa + ops->sb + ops->ss + ops->pa + ops->pb
		+ ops->ra + ops->rb + ops->rr + ops->rra + ops->rrb + ops->rrr;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putfloat_fd(dis * 100, 2);
	ft_putstr_fd("%\n", 2);
	print_strategy(dis, flag);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	ops_print(ops);
}
