/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:13:36 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/14 01:26:27 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_it(t_nums **nums, char c)
{
	t_nums	*temp;

	temp = *nums;
	if (*nums)
	{
		if (c == 'a')
			ft_printf("sa\n");
		if (c == 'b')
			ft_printf("sb\n");
		*nums = (*nums)->next;
		temp -> next = (*nums)-> next;
		(*nums)-> next = temp;
	}
}

void	swap_both(t_nums **stack_a, t_nums **stack_b)
{
	ft_printf("ss\n");
	swap_it(stack_a, '0');
	swap_it(stack_b, '0');
}

void	rotate_it(t_nums **nums, char c)
{
	t_nums	*temp;

	temp = *nums;
	if (*nums && get_last((*nums)-> next))
	{
		if (c == 'a')
			ft_printf("ra\n");
		if (c == 'b')
			ft_printf("rb\n");
		*nums = (*nums)->next;
		get_last(*nums)-> next = temp;
		temp -> next = NULL;
	}
}

void	rotate_both(t_nums **stack_a, t_nums **stack_b)
{
	ft_printf("rr\n");
	rotate_it(stack_a, '0');
	rotate_it(stack_b, '0');
}
