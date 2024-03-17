/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:46:40 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/13 21:59:58 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lowest(int num, t_nums *nums)
{
	int	max;
	int	min;
	int	f;

	max = INT_MAX;
	min = INT_MAX;
	f = 0;
	while (nums)
	{
		if (min > nums -> num)
			min = nums -> num;
		if (num < nums -> num && max > nums -> num)
		{
			f++;
			max = nums -> num;
		}
		nums = nums->next;
	}
	if (!f)
		return (min);
	return (max);
}

int	get_index(int num, t_nums *nums)
{
	while (nums)
	{
		if (num == nums -> num)
			return (nums->index);
		nums = nums -> next;
	}
	return (0);
}

void	get_cost(int num, t_nums *stack_b, t_nums *stack_a, t_cost *cost)
{
	cost -> b = num;
	cost -> a = get_lowest(cost -> b, stack_a);
	cost -> b_moves = get_index(cost->b, stack_b);
	cost -> b_operation = 1;
	cost -> a_operation = 1;
	if (cost -> b_moves > count_node_len(stack_b) / 2)
	{
		cost -> b_moves = count_node_len(stack_b) - cost -> b_moves;
		cost -> b_operation = -1;
	}
	cost -> a_moves = get_index(cost->a, stack_a);
	if (cost -> a_moves > count_node_len(stack_a) / 2)
	{
		cost -> a_moves = count_node_len(stack_a) - cost -> a_moves;
		cost -> a_operation = -1;
	}
}

t_cost	compare_cost(t_cost temp, t_cost top_move)
{
	if (temp.a_moves + temp.b_moves < top_move.a_moves + top_move.b_moves)
		return (temp);
	return (top_move);
}

t_cost	cal_cost(t_nums *stack_b, t_nums *stack_a)
{
	t_cost	top_move;
	t_nums	*temp;
	t_cost	temp_cost;

	temp = stack_b;
	set_index(stack_b);
	set_index(stack_a);
	get_cost(temp->num, stack_b, stack_a, &top_move);
	while (temp)
	{
		get_cost(temp->num, stack_b, stack_a, &temp_cost);
		top_move = compare_cost(temp_cost, top_move);
		temp = temp -> next;
	}
	return (top_move);
}
