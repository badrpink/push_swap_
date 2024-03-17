/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:06:48 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/17 20:50:01 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_reverse_both(t_nums **stack_a, t_nums **stack_b)
{
	if (*stack_a)
		reverse_rotate(stack_a);
	if (*stack_b)
		reverse_rotate(stack_b);
}

void	swap_it(t_nums **nums)
{
	t_nums	*temp;

	temp = *nums;
	if (*nums)
	{
		*nums = (*nums)-> next;
		temp -> next = (*nums)-> next;
		(*nums)-> next = temp;
	}
}

void	swap_both(t_nums **stack_a, t_nums **stack_b)
{
	if (*stack_a)
		swap_it(stack_a);
	if (*stack_b)
		swap_it(stack_b);
}

void	rotate_it(t_nums **nums)
{
	t_nums	*temp;

	temp = *nums;
	if (*nums && get_last((*nums)-> next))
	{
		*nums = (*nums)->next;
		get_last(*nums)-> next = temp;
		temp -> next = NULL;
	}
}

void	rotate_both(t_nums **stack_a, t_nums **stack_b)
{
	if (*stack_a)
		rotate_it(stack_a);
	if (*stack_b)
		rotate_it(stack_b);
}
