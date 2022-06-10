/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:38:18 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/11/17 19:52:46 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	dst_size = 0;
	src_size = ft_strlen(src);
	while (dst_size < size && dst[dst_size])
		dst_size++;
	if (size <= dst_size)
		return (size + src_size);
	while (size && (--size - dst_size) && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}
