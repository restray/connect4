/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:57:09 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/11/20 13:00:49 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *str;
	char *str2;

	str = (char *)dest;
	str2 = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (n)
	{
		*str = *str2;
		n--;
		str++;
		str2++;
	}
	return (dest);
}
