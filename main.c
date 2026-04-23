/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:01:23 by marvin            #+#    #+#             */
/*   Updated: 2026/03/11 20:01:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	run_algorithm(t_node **a, t_node **b, t_range *r, t_ops *ops)
{
	double	dis;

	dis = disorder(*a);
	if (r->flag == 1)
		simple_algorithm(a, b, ops);
	else if (r->flag == 2)
		medium_algorithm(a, b, ops);
	else if (r->flag == 3)
		complex_algorithm(a, b, ops);
	else if (r->flag == 4)
		adaptive_algorithm(a, b, ops);
	else if (r->count <= 3)
		sorting_three(a, ops);
	else if (r->count <= 5)
		simple_algorithm(a, b, ops);
	else if (dis < 0.2)
		simple_algorithm(a, b, ops);
	else if (dis < 0.5)
		medium_algorithm(a, b, ops);
	else
		complex_algorithm(a, b, ops);
}

char	**get_input(int argc, char **argv, int start)
{
	char	**arr;

	arr = obt_arr(argc - start, argv + start,
			total_nums(argc - start, argv + start));
	if (!arr)
		error_exit();
	return (arr);
}

t_node	*build_stacks(char **arr, t_node **stack_b)
{
	*stack_b = NULL;
	return (input_to_stack(arr));
}

void	run_bench(t_node **a, t_node **b, t_range *range, int bench)
{
	t_ops	ops;
	t_ops	*ops_ptr;
	double	dis;

	ops = (t_ops){0};
	ops_ptr = NULL;
	dis = disorder(*a);
	if (bench)
		ops_ptr = &ops;
	run_algorithm(a, b, range, ops_ptr);
	if (bench)
		bench_print(dis, &ops, range->flag);
}

int	main(int argc, char **argv)
{
	int		start;
	char	**arr;
	t_node	*stack_a;
	t_node	*stack_b;
	t_range	range;

	if (argc < 2)
		return (0);
	range.flag = flags_checking(argc, argv);
	start = count_flags(argc, argv) + 1;
	if (!is_validated(argc, argv))
		error_exit();
	arr = get_input(argc, argv, start);
	stack_a = build_stacks(arr, &stack_b);
	range.count = total_nums(argc - start, argv + start);
	if (stack_a && !is_sorted(stack_a))
		run_bench(&stack_a, &stack_b, &range, has_bench(argc, argv));
	free_array(arr, range.count);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
