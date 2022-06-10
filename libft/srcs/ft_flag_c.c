/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:47:02 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/02 18:45:59 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_flag_c(int c, t_flags flag)
{
	int size;
	int	moins;

	size = 0;
	moins = flag.moins;
	if (moins == 1)
		ft_putchar(c);
	flag.zero = 0;
	flag.moins = 1;
	size = ft_display_flag_option_taille(flag);
	if (moins == 0)
		ft_putchar(c);
	return (size + 1);
}
