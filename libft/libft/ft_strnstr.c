/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:53:19 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/11/20 14:10:01 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	little_size;

	i = 0;
	little_size = ft_strlen(little) - 1;
	if (!little || *little == '\0')
		return ((char *)big);
	while (big[i] && i < len - little_size)
	{
		y = 0;
		while (i + y < len && big[i + y] == little[y])
		{
			if (little[y + 1] == '\0')
				return ((char *)&big[i]);
			y++;
		}
		i++;
	}
	return (NULL);
}
