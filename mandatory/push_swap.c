/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:47:57 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/17 20:47:27 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_replica(t_nums *nums)
{
	int		num;
	t_nums	*temp;

	while (nums)
	{
		num = nums ->num;
		if (nums -> num < -2147483648 || nums->num > 2147483647)
			return (0);
		temp = nums -> next;
		while (temp)
		{
			if (temp->num == num)
				return (0);
			temp = temp -> next;
		}
		nums = nums -> next;
	}
	return (1);
}

t_nums	*store_it(char **strs, t_nums *nums)
{
	t_nums	*temp;

	while (*strs)
	{
		temp = ft_new_nums(ft_atoi(*strs));
		ft_add_num(&nums, temp);
		strs++;
	}
	return (nums);
}

int	check_storted(t_nums *nums)
{
	int	temp;

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

int	main(int ac, char **av)
{
	t_nums	*nums;
	char	*str;
	char	**strs;

	nums = NULL;
	if (ac >= 2)
	{
		str = join_it(ac, av + 1);
		if (!str)
			return (ft_printf("Error\n"), 0);
		if (!check_it(str))
			return (free(str), ft_printf("Error\n"), 0);
		strs = ft_split(str, ' ');
		free(str);
		nums = store_it(strs, nums);
		if (!nums)
			return (clear_strs(strs), ft_printf("Error\n"), 0);
		clear_strs(strs);
		if (!check_replica(nums))
			return (clear_nums(nums), ft_printf("Error\n"), 0);
		if (!check_storted(nums))
			sort_it(&nums);
		clear_nums(nums);
	}
	return (0);
}
