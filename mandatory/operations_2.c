/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:13:36 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/13 23:23:51 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nums	*get_last(t_nums *nums)
{
	if (nums)
	{
		while (nums->next)
			nums = nums->next;
		return (nums);
	}
	else
		return (NULL);
}

t_nums	*bef_last(t_nums *nums)
{
	t_nums	*temp;

	while (nums->next)
	{
		temp = nums;
		nums = nums -> next;
	}
	return (temp);
}

void	reverse_rotate(t_nums **nums, char c)
{
	t_nums	*temp;
	t_nums	*befor_last;

	temp = *nums;
	befor_last = bef_last(*nums);
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
	*nums = get_last(*nums);
	get_last(*nums)->next = temp;
	befor_last->next = NULL;
}

void	push_to(t_nums **src, t_nums **dest, char c)
{
	t_nums	*temp;

	temp = *src;
	if (*src)
	{
		if (c == 'a')
			ft_printf("pa\n");
		if (c == 'b')
			ft_printf("pb\n");
		*src = (*src)->next;
		if (*dest)
		{
			temp->next = *dest;
			*dest = temp;
		}
		else
		{
			*dest = temp;
			(*dest)->next = NULL;
		}
	}
}

void	rotate_reverse_both(t_nums **stack_a, t_nums **stack_b)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_a, '0');
	reverse_rotate(stack_b, '0');
}
