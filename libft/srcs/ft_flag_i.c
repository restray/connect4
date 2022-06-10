/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:52:15 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/03 10:31:22 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_flag_i_init(t_flags *flag, int number, int *size)
{
	char	*num;
	char	*tmp;

	if ((*flag).point == 0 && number == 0)
	{
		*size = ft_putchar_size(0, (*flag).taille + 1) - 1;
		return (NULL);
	}
	num = ft_itoa(number);
	if (number < 0 && ((*flag).point >= 0 || (*flag).zero > 0))
	{
		if ((*flag).zero > 0 && (*flag).point < 0)
			ft_putstr_len("-", 1);
		tmp = ft_strtrim(num, "-");
		free(num);
		num = tmp;
		(*flag).zero = 1;
		(*flag).taille -= 1;
		(*size)++;
	}
	return (num);
}

static void	ft_flag_i_moins(t_flags flag, char *num, int number, int *size)
{
	if (flag.point >= 0)
	{
		if (number < 0)
			ft_putstr_len("-", 1);
		(*size) += ft_putspace_int(flag.point - 1, ft_strlen(num) - 1, 1);
	}
	(*size) += ft_putstr_len(num, ft_strlen(num));
}

int			ft_display_flag_integer(int number, t_flags flag)
{
	char			*num;
	int				size;

	size = 0;
	num = ft_flag_i_init(&flag, number, &size);
	if (num == NULL)
		return (size);
	if (flag.moins == 1)
		ft_flag_i_moins(flag, num, number, &size);
	if (flag.point >= 0)
	{
		if ((size_t)flag.point < ft_strlen(num))
			flag.point = ft_strlen(num);
		flag.taille -= flag.point;
		size += ft_putspace_int(flag.taille, 0, 0);
	}
	else
		size += ft_putspace_int(flag.taille, ft_strlen(num),
								flag.etoileneg == 1 ? 0 : flag.zero);
	if (flag.moins == 0)
		ft_flag_i_moins(flag, num, number, &size);
	free(num);
	return (size);
}
