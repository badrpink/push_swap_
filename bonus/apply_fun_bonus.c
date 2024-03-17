/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fun_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:36:48 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/17 20:48:49 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	apply_fun(char *str, t_nums **stack_a, t_nums **stack_b)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_it(stack_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_it(stack_b);
	else if (!ft_strncmp(str, "ss\n", 3))
		swap_both(stack_a, stack_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		push_to(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb\n", 3))
		push_to(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate_it(stack_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate_it(stack_b);
	else if (!ft_strncmp(str, "rr\n", 3))
		rotate_both(stack_a, stack_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rotate_reverse_both(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	check_sorted(t_nums *nums)
{
	int	temp;

	if (nums)
	{
		temp = nums -> num;
		nums = nums -> next;
		while (nums)
		{
			if (temp > nums -> num)
				return (0);
			temp = nums -> num;
			nums = nums -> next;
		}
		return (1);
	}
	return (0);
}

void	apply_and_check_sort(t_nums **stack_a)
{
	char	*str;
	t_nums	*stack_b;

	stack_b = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!apply_fun(str, stack_a, &stack_b))
		{
			free(str);
			clear_nums(*stack_a);
			ft_printf("Error\n");
			exit(1);
		}
		free(str);
	}
	if (check_sorted(*stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
