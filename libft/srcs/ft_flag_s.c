/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:47:34 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/02 18:47:37 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_flag_s_space(t_flags flag, int tmp_taille, int *size)
{
	while (tmp_taille > flag.taille)
	{
		(*size) += ft_putchar(' ');
		tmp_taille--;
	}
}

int			ft_display_flag_s(char *s, t_flags flag)
{
	int		size;
	int		tmp_taille;

	size = 0;
	if (s == NULL)
		s = "(null)";
	if ((flag.point >= 0 && (size_t)flag.point > ft_strlen(s)) ||
							flag.point < 0)
	{
		flag.point = ft_strlen(s);
		tmp_taille = flag.taille;
		flag.taille = ft_strlen(s);
	}
	else
	{
		tmp_taille = flag.taille;
		flag.taille = flag.point;
	}
	if (flag.moins == 1)
		size += ft_putstr_len(s, flag.taille);
	ft_display_flag_s_space(flag, tmp_taille, &size);
	if (flag.moins == 0)
		size += ft_putstr_len(s, flag.taille);
	return (size);
}
