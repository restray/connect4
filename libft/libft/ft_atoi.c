/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:49:30 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/11/18 15:57:33 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int neg;
	int atoi;
	int i;

	atoi = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		neg = (str[i++] == '-' ? -neg : neg);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			atoi = (atoi * 10) + (str[i] - '0');
		else
			return (atoi * neg);
		i++;
	}
	return (atoi * neg);
}
