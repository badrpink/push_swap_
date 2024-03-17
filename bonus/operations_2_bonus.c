/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:06:48 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/14 00:47:19 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

	temp = NULL;
	if (nums)
	{
		while (nums->next)
		{
			temp = nums;
			nums = nums -> next;
		}
	}
	return (temp);
}

void	reverse_rotate(t_nums **nums)
{
	t_nums	*temp;
	t_nums	*befor_last;

	temp = *nums;
	befor_last = bef_last(*nums);
	if (*nums && (*nums)-> next)
	{
		*nums = get_last(*nums);
		get_last(*nums)->next = temp;
		befor_last->next = NULL;
	}
}

void	push_to(t_nums **src, t_nums **dest)
{
	t_nums	*temp;

	if (*src)
	{
		temp = *src;
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
