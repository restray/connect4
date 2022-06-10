/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:18:23 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/11/20 12:58:06 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_copy;
	unsigned char	*src_copy;

	src_copy = (unsigned char*)src;
	dst_copy = (unsigned char*)dest;
	i = 0;
	while (i < n && src_copy[i] != (unsigned char)c)
	{
		dst_copy[i] = src_copy[i];
		i++;
	}
	if (i == n)
		return (NULL);
	dst_copy[i] = src_copy[i];
	return (&dst_copy[i + 1]);
}
