/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:36:45 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/17 19:56:55 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	unsigned long	result;
	int				i;
	int				signal;
	long			ret;

	i = 0;
	result = 0;
	signal = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signal *= -1;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i++] - 48;
		if ((result > 2147483647) && signal == 1)
			return (ft_printf("Error\n"), exit(1), 0);
		else if ((result > 2147483648) && signal == -1)
			return (ft_printf("Error\n"), exit(1), 0);
	}
	ret = result;
	return (ret * signal);
}
