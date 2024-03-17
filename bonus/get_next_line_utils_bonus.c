/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:05:31 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/12 21:03:49 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	count_len(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	check_nl(char *str)
{
	if (!str)
		return (1);
	while (*str)
		if (*(str++) == '\n')
			return (0);
	return (1);
}

void	copy_it(char *dest, char *src)
{
	if (!src)
		return ;
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
}
