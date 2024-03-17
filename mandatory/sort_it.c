/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:03:14 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/13 23:21:07 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nums(t_nums *nums)
{
	int	count;

	count = 0;
	while (nums)
	{
		count++;
		nums = nums -> next;
	}
	return (count);
}

void	sort_three(t_nums **nums)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*nums)-> num;
	n2 = (*nums)-> next -> num;
	n3 = (*nums)-> next -> next -> num;
	if ((*nums)-> num > n2 && (*nums)-> num < n3 && n2 < n3)
		swap_it(nums, 'a');
	else if ((*nums)-> num > n2 && n2 > n3)
	{
		swap_it(nums, 'a');
		reverse_rotate(nums, 'a');
	}
	else if ((*nums)-> num > n2 && n2 < n3)
		rotate_it(nums, 'a');
	else if ((*nums)-> num < n2 && (*nums)-> num < n3)
	{
		swap_it(nums, 'a');
		rotate_it(nums, 'a');
	}
	else if ((*nums)-> num < n2 && (*nums)-> num > n3)
		reverse_rotate(nums, 'a');
}

void	sort_it(t_nums **stack_a)
{
	t_nums	*stack_b;

	stack_b = NULL;
	if (count_nums(*stack_a) == 2)
		swap_it(stack_a, 'a');
	else if (count_nums(*stack_a) == 3)
		sort_three(stack_a);
	else if (count_nums(*stack_a) <= 6)
		best_move(stack_a, &stack_b);
	else
	{
		set_i(*stack_a);
		sort_a(stack_a, &stack_b);
		sort_b(stack_a, &stack_b);
	}
}
