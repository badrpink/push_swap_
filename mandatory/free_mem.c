/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:45:04 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/13 21:48:39 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_strs(char **strs)
{
	char	**clear;

	clear = strs;
	if (strs)
	{
		while (*strs)
			free(*(strs++));
		free(clear);
	}
}

void	clear_nums(t_nums *nums)
{
	t_nums	*clear;

	if (nums)
	{
		while (nums)
		{
			clear = nums;
			nums = nums -> next;
			free(clear);
		}
	}
}

int	count_node_len(t_nums *num)
{
	int	count;

	count = 0;
	while (num)
	{
		count++;
		num = num -> next;
	}
	return (count);
}
