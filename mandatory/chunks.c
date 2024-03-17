/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:33 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/13 23:20:50 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all(t_nums *stacks)
{
	while (stacks)
	{
		if (stacks -> cost != 1)
			return (0);
		stacks = stacks ->next;
	}
	return (1);
}

void	set_i(t_nums *stack_t)
{
	static int	i;
	long		min;
	t_nums		*temp;
	t_nums		*stack;

	while (!check_all(stack_t))
	{
		min = 2147483648;
		stack = stack_t;
		while (stack)
		{
			if (stack -> num < min && stack -> cost != 1)
			{
				min = stack -> num;
				temp = stack;
			}
			stack = stack -> next;
		}
		temp -> cost = 1;
		temp -> index = i++;
	}
}

t_pos	get_the_biggest(t_nums *stack)
{
	t_pos	position;
	int		stack_len;
	int		count ;

	count = 0;
	stack_len = count_nums(stack);
	position.index = INT_MIN;
	while (stack)
	{
		if (stack -> index > position.index)
		{
			position.index = stack->index;
			position.rank = count;
		}
		count++;
		stack = stack -> next;
	}
	position.operation = 1;
	if (position.rank > stack_len / 2)
	{
		position.rank = stack_len - position.rank;
		position.operation = -1;
	}
	return (position);
}

void	sort_a(t_nums **stack_a, t_nums **stack_b)
{
	int	i;
	int	j;

	j = count_nums(*stack_a) / 15;
	if (count_nums(*stack_a) <= 150)
		j = count_nums(*stack_a) / 7;
	i = 0;
	while (count_nums(*stack_a))
	{
		if ((*stack_a)-> index <= i)
		{
			push_to(stack_a, stack_b, 'b');
			i++;
		}
		else if ((*stack_a)-> index <= i + j)
		{
			push_to(stack_a, stack_b, 'b');
			rotate_it(stack_b, 'b');
			i++;
		}
		else
			rotate_it(stack_a, 'a');
	}
}

void	sort_b(t_nums **stack_a, t_nums **stack_b)
{
	t_pos	position;

	position = get_the_biggest(*stack_b);
	while (count_nums(*stack_b))
	{
		position = get_the_biggest(*stack_b);
		while (position.rank)
		{
			if (position.operation == 1)
				rotate_it(stack_b, 'b');
			else
				reverse_rotate(stack_b, 'b');
			position.rank--;
		}
		push_to(stack_b, stack_a, 'a');
	}
}
