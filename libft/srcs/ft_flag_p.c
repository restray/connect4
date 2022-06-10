/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:47:02 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/03 11:02:20 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_flag_p_dec_to_hex(unsigned long long p, int *exist,
										int *size)
{
	char			ptr[100];
	char			*ptr_copy;
	int				i;
	int				j;

	ptr_copy = ft_calloc(100, sizeof(char));
	i = 0;
	if (p == 0)
		ptr[i++] = '0';
	while (p != 0)
	{
		if (p % 16 < 10)
			ptr[i++] = p % 16 + '0';
		else
			ptr[i++] = p % 16 - 10 + 'a';
		p = p / 16;
	}
	j = 0;
	while (i > 0)
		ptr_copy[j++] = ptr[--i];
	*exist = j;
	*size = j + 2;
	return (ptr_copy);
}

int					ft_display_flag_p(unsigned long long p, t_flags flag)
{
	int				size;
	char			*ptr;
	int				exist;
	int				tmp;

	size = 0;
	ptr = ft_flag_p_dec_to_hex(p, &exist, &size);
	if (flag.moins == 0)
	{
		tmp = ft_putchar_size(0, flag.taille - size + 1) - 1;
		size += tmp >= 0 ? tmp : 0;
	}
	ft_putstr_len("0x", 2);
	ft_putstr_len(ptr, ft_strlen(ptr));
	if (flag.moins == 1)
	{
		tmp = ft_putchar_size(0, flag.taille - size + 1) - 1;
		size += tmp >= 0 ? tmp : 0;
	}
	free(ptr);
	return (size);
}
