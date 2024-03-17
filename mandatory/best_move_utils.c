/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:56:28 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/13 23:19:29 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_nums *nums)
{
	int	i;

	i = 0;
	while (nums)
	{
		nums -> index = i++;
		nums = nums -> next;
	}
}

void	sort_all(t_cost move, t_nums **stack_a, t_nums **stack_b)
{
	if (move.a_operation == move.b_operation)
	{
		while (move.b_moves-- && move.a_moves--)
		{
			if (move.b_operation == 1)
				rotate_both(stack_b, stack_a);
			else
				rotate_reverse_both(stack_b, stack_a);
		}
	}
	while (move.b != (*stack_b)-> num)
	{
		if (move.b_operation == 1)
			rotate_it(stack_b, 'b');
		else
			reverse_rotate(stack_b, 'b');
		move.b_moves--;
	}
	while (move.a_moves--)
	{
		if (move.a_operation == 1)
			rotate_it(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
}

void	best_move(t_nums **stack_a, t_nums **stack_b)
{
	t_cost	move;

	if (count_nums(*stack_a) > 3)
	{
		while (count_nums(*stack_a) != 3)
			push_to(stack_a, stack_b, 'b');
	}
	if (!check_storted(*stack_a))
		sort_three(stack_a);
	while (count_nums(*stack_b))
	{
		move = cal_cost(*stack_b, *stack_a);
		sort_all(move, stack_a, stack_b);
		push_to(stack_b, stack_a, 'a');
	}
	while (!check_storted(*stack_a))
		rotate_it(stack_a, 'a');
}
