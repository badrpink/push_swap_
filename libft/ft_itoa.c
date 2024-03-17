/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:10:55 by mel-ward          #+#    #+#             */
/*   Updated: 2023/11/03 14:21:12 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int nb)
{
	int	count;

	count = 1;
	while (nb / 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static int	cal(int nb)
{
	int	count;

	count = 1;
	while (--nb > -1)
		count *= 10;
	return (count);
}

static void	alloc(char *ret, int count, unsigned int nb, int i)
{
	while (count--)
	{
		ret[i] = nb / cal(count) + 48;
		nb %= cal(count);
		i++;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*ret;
	int				i;
	int				count;
	int				p;

	p = 1;
	nb = n;
	i = 0;
	if (n < 0)
		p++;
	if (!n)
		return (ft_strdup("0"));
	count = count_digit(n);
	ret = (char *)ft_calloc(sizeof(char), count + p);
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		nb = -n;
		ret[i++] = '-';
	}
	alloc(ret, count, nb, i);
	return (ret);
}
