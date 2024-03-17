/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:45:32 by mel-ward          #+#    #+#             */
/*   Updated: 2023/11/03 12:40:52 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!len)
		return (dst);
	if (!src && !dst)
		return (NULL);
	if (dst > src)
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
