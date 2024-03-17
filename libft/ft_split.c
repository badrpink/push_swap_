/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:41:49 by mel-ward          #+#    #+#             */
/*   Updated: 2023/11/06 23:42:44 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*ft_allocate(const char *str, char c, int *i)
{
	int		size;
	int		n;
	char	*word;

	size = 0;
	n = 0;
	if (!str)
		return (NULL);
	while (str[*i] && str[*i] == c)
		(*i)++;
	while (str[*i] && str[*i] != c)
	{
		(*i)++;
		size++;
	}
	word = (char *)malloc(size + 1);
	if (!word)
		return (NULL);
	while (n < size && *str)
	{
		word[n] = str[(*i) - size + n];
		n++;
	}
	word[n] = 0;
	return (word);
}

static void	free_it(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		c_words;
	char	**ret;
	int		n;

	if (!str)
		return ((char **)ft_strdup(""));
	c_words = count_words(str, c);
	ret = (char **)malloc((c_words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	n = 0;
	while (n < c_words && *str)
	{
		ret[n] = ft_allocate(str, c, &i);
		if (!ret[n])
		{
			free_it(ret);
			return (NULL);
		}
		n++;
	}
	ret[n] = 0;
	return (ret);
}
