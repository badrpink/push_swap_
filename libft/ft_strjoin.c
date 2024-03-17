/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:50:34 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/04 14:11:30 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char*s2)
{
	char	*ret;

	if (!s2 && !s1)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ret = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	ret = (char *)ft_memcpy(ret, s1, ft_strlen(s1));
	ft_strlcat(ret, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	free(s1);
	return (ret);
}
