/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:48:01 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/13 23:24:58 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libc.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct t_nums
{
	long			num;
	int				cost;
	int				index;
	struct t_nums	*next;
}	t_nums;

typedef struct s_cost
{
	int	b;
	int	a;
	int	b_moves;
	int	a_moves;
	int	b_operation;
	int	a_operation;
}	t_cost;

typedef struct t_pos
{
	int	index;
	int	rank;
	int	operation;
}	t_pos;

char	*join_it(int ac, char **av);
int		check_empty(char *str);
t_nums	*ft_new_nums(long num);
void	ft_add_num(t_nums **nums, t_nums *new);
int		check_it(char *str);
void	set_index(t_nums *nums);
void	sort_it(t_nums **nums);
void	print_node(t_nums *num);
int		get_lowest(int num, t_nums *nums);
t_cost	cal_cost(t_nums *stack_b, t_nums *stack_a);
int		check_storted(t_nums *nums);
void	swap_it(t_nums **nums, char c);
void	swap_both(t_nums **stack_a, t_nums **stack_b);
void	rotate_it(t_nums **nums, char c);
void	rotate_both(t_nums **stack_a, t_nums **stack_b);
void	reverse_rotate(t_nums **nums, char c);
void	push_to(t_nums **src, t_nums **dest, char c);
void	rotate_reverse_both(t_nums **stack_a, t_nums **stack_b);
void	clear_strs(char **strs);
void	clear_nums(t_nums *nums);
int		count_node_len(t_nums *num);
int		check_all(t_nums *stacks);
void	set_i(t_nums *stack_t);
t_pos	get_the_biggest(t_nums *stack);
void	sort_a(t_nums **stack_a, t_nums **stack_b);
void	sort_b(t_nums **stack_a, t_nums **stack_b);
int		count_nums(t_nums *nums);
void	sort_three(t_nums **nums);
void	set_index(t_nums *nums);
void	sort_all(t_cost move, t_nums **stack_a, t_nums **stack_b);
void	best_move(t_nums **stack_a, t_nums **stack_b);
t_cost	compare_cost(t_cost temp, t_cost top_move);
void	get_cost(int num, t_nums *stack_b, t_nums *stack_a, t_cost *cost);
int		get_index(int num, t_nums *nums);
t_nums	*get_last(t_nums *nums);
t_nums	*bef_last(t_nums *nums);
#endif