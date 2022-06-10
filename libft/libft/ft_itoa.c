/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:32:41 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/11/23 09:50:11 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	unsigned int	i;
	unsigned int	n1;

	if (n == 0)
		return (2);
	i = (n < 0 ? 2 : 1);
	n1 = (n < 0 ? (unsigned int)-n : (unsigned int)n);
	while (n1 > 9)
	{
		n1 /= 10;
		i++;
	}
	return (++i);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	unsigned int	n1;

	i = ft_intlen(n);
	str = malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	n1 = (n < 0 ? (unsigned int)-n : (unsigned int)n);
	str[--i] = '\0';
	while (n1 > 9)
	{
		str[--i] = n1 % 10 + '0';
		n1 /= 10;
	}
	str[--i] = n1 + '0';
	return (str);
}
