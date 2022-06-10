/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_pourcentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:47:19 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/02 18:47:22 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_flag_pourcentage(t_flags flag)
{
	int	size;

	size = 0;
	if (flag.moins == 0)
		size += ft_putchar_size(flag.zero, flag.taille);
	ft_putchar('%');
	size++;
	if (flag.moins == 1)
		size += ft_putchar_size(flag.zero, flag.taille);
	return (size);
}
