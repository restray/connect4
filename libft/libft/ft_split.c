/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:20:52 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/11/19 15:32:01 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_is_splitter(char c, char splitter)
{
	return (splitter == c ? 0 : 1);
}

static unsigned int	ft_count_splitter(const char *str, char charset)
{
	unsigned int counter;
	unsigned int i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && ft_is_splitter(str[i], charset) == 1)
			counter++;
		else if (i > 0 && ft_is_splitter(str[i - 1], charset) == 0 &&
				ft_is_splitter(str[i], charset) == 1)
			counter++;
		i++;
	}
	return (counter);
}

static char			*ft_cpy(const char *str, char charset, int beginning)
{
	unsigned int	i;
	char			*saved;

	saved = malloc(sizeof(char) * (ft_strlen(str) - beginning + 1));
	if (!saved)
		return (NULL);
	i = beginning;
	while (str[i] != '\0')
	{
		if (ft_is_splitter(str[i], charset) == 0)
		{
			saved[i - beginning] = '\0';
		}
		else
		{
			saved[i - beginning] = str[i];
		}
		i++;
	}
	saved[i - beginning] = '\0';
	return (saved);
}

char				**ft_split(const char *str, char charset)
{
	char			**split;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	split = malloc(sizeof(char *) * (ft_count_splitter(str, charset) + 1));
	if (!split)
		return (malloc(sizeof(char *)));
	size = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && ft_is_splitter(str[i], charset) == 1)
			split[size++] = ft_cpy(str, charset, i);
		else if (i > 0 && ft_is_splitter(str[i - 1], charset) == 0 &&
				ft_is_splitter(str[i], charset) == 1)
			split[size++] = ft_cpy(str, charset, i);
		i++;
	}
	split[size] = 0;
	return (split);
}
