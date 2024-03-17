/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:47:57 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/17 21:40:31 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_empty(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!*str)
		return (1);
	return (0);
}

char	*join_it(int ac, char **av)
{
	int		i;
	char	*str;

	str = ft_strdup("");
	i = 0;
	while (i < ac - 1)
	{
		str = ft_strjoin(str, av[i++]);
		if (check_empty(av[i - 1]))
			return (free(str), NULL);
		if (i + 1 < ac)
			str = ft_strjoin(str, " ");
	}
	return (str);
}

t_nums	*ft_new_nums(long num)
{
	t_nums	*new;

	new = malloc(sizeof(t_nums));
	if (!new)
		return (NULL);
	new -> num = num;
	new -> next = NULL;
	return (new);
}

void	ft_add_num(t_nums **nums, t_nums *new)
{
	t_nums	*temp;

	temp = *nums;
	if (*nums && new)
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
	else if (!*nums)
		*nums = new;
}

int	check_it(char *str)
{
	while (*str)
	{
		if (!ft_strchr("+- ", *str) && !ft_isdigit(*str))
			return (0);
		if (ft_strchr("+-", *str) && !ft_isdigit(*(str + 1)))
			return (0);
		if (ft_strchr("+-", *str) && ft_isdigit(*(str - 1))
			&& ft_isdigit(*(str + 1)))
			return (0);
		str++;
	}
	return (1);
}
