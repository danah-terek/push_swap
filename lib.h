/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 01:51:05 by marvin            #+#    #+#             */
/*   Updated: 2026/03/12 01:51:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_range
{
	int	min;
	int	max;
	int	size;
	int	bit;
	int	flag;
	int	count;
}	t_range;

t_node	*new_node(int value);
t_node	*input_to_stack(char **arr);
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
int		find_max(t_node *stack);
int		find_min(t_node *stack);
t_node	*last_node(t_node *stack);
void	add_back(t_node **stack, t_node *new);
void	free_stack(t_node *stack);
double	disorder(t_node *stack);
void	append_node(t_node **stack, t_node **current, int val);
int		duplicated(char **str);
void	swap(t_node **stack);
void	sa(t_node **stack_a, t_ops *ops);
void	sb(t_node **stack_b, t_ops *ops);
void	ss(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	pa(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	pb(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	rotate(t_node **stack);
void	ra(t_node **stack_a, t_ops *ops);
void	rb(t_node **stack_b, t_ops *ops);
void	rr(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a, t_ops *ops);
void	rrb(t_node **stack_b, t_ops *ops);
void	rrr(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	sorting_three(t_node **stack, t_ops *ops);
void	push_all_except_three(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	simple_algorithm(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	medium_algorithm(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	complex_algorithm(t_node **stack_a, t_node **stack_b, t_ops *ops);
void	adaptive_algorithm(t_node **stack_a, t_node **stack_b, t_ops *ops);
int		*fill_array_with_values_from_stack(t_node *stack, int size);
void	sort_array(int *arr, int size);
void	replace_stack_values_with_index(t_node **stack, int *arr, int size);
long	ft_atoi(const char *nptr);
int		ft_count_words(char const *str, char c);
char	**ft_split(char const *s, char c);
char	**ft_split_words(char const *s, char c, char **s2, int num_word);
char	**free_array(char **ptr, int i);
int		is_number(char *str);
char	*ft_strdup(const char *s);
void	error_exit(void);
int		copy_input_split_to_array(char **arr, char **tmp, int j);
char	**obt_arr(int argc, char **argv, int total_nums);
char	**prepare_array(int ac, char **av, int *count);
long	is_validated(int ac, char **av);
int		total_nums(int argc, char **argv);
int		flags_checking(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		count_flags(int argc, char **argv);
int		has_bench(int argc, char **argv);
int		is_flag(char *str);
void	bench_print(double dis, t_ops *ops, int flag);
void	one_radix_pass(t_node **s_a, t_node **s_b, t_range *range, t_ops *ops);
void	push_chunk(t_node **a, t_node **b, t_range *range, t_ops *ops);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putfloat_fd(double n, int fd);
int		ft_sqrt(int n);
void	run_algorithm(t_node **a, t_node **b, t_range *range, t_ops *ops);
void	run_bench(t_node **a, t_node **b, t_range *range, int bench);
void	rotate_to_min(t_node **stack, t_ops *ops);
int		find_position_of_min(t_node *stack);
void	print_strategy(double dis, int flag);
void	ops_print(t_ops *ops);
void	index_stack(t_node **stack_a);
void	push_b_back_to_a(t_node **stack_a, t_node **stack_b, t_ops *ops);
int		get_max_bits(int max);
char	**get_input(int argc, char **argv, int start);
t_node	*build_stacks(char **arr, t_node **stack_b);
int		main(int argc, char **argv);
void	chunks(t_node **stack_a, t_node **stack_b, int n, t_ops *ops);
int		find_position_of_max_in_stackb(t_node *stack_b);
void	push_back(t_node **stack_a, t_node **stack_b, t_ops *ops);
char	*ft_putword(char *word, char const *s, int i, int word_len);

#endif