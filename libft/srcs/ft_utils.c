/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:48:42 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/10 21:53:42 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	while (str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_putstr_len(char *s, size_t len)
{
	size_t	size;

	size = 0;
	while (s[size] && size < len)
		ft_putchar(s[size++]);
	return (size);
}

int		ft_putchar_size(int zero, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		ft_putchar(zero > 0 ? '0' : ' ');
	return (size < 0 ? 0 : size);
}

int		ft_putspace_int(int taille, int longueur, int zero)
{
	int	size;

	size = 0;
	while (taille-- > longueur)
	{
		ft_putchar(zero ? '0' : ' ');
		size++;
	}
	return (size);
}
