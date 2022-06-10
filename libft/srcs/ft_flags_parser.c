/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:48:24 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/02 18:48:25 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_exist(char c)
{
	return (c == 'c' || c == 's' ||
			c == 'p' || c == 'x' || c == 'X' ||
			c == 'd' || c == 'i' ||
			c == 'u' || c == '%');
}

int		ft_flag_option_exist(char c)
{
	return (c == '-' || c == '.' || c == '0' || c == ' ' || c == '*');
}

void	ft_parse_flag(char *string, unsigned int *i, t_flags *flag,
						va_list arg_list)
{
	while (string[*i])
	{
		if (!ft_isdigit(string[*i]) && !ft_flag_exist(string[*i]) &&
			!ft_flag_option_exist(string[*i]))
			break ;
		if (string[*i] == '0' && (*flag).taille == 0 && (*flag).moins == 0)
			(*flag).zero = 1;
		if (string[*i] == '.')
			ft_flag_point(string, i, flag, arg_list);
		if (string[*i] == '-')
			ft_flag_moins(flag);
		if (string[*i] == '*')
			ft_flag_etoile(flag, arg_list);
		if (ft_isdigit(string[*i]))
			ft_flag_digit(flag, string[*i]);
		if (ft_flag_exist(string[*i]))
		{
			(*flag).type = string[*i];
			break ;
		}
		(*i)++;
	}
}

int		ft_display_flag_option_taille(t_flags flag)
{
	int	size;

	size = 0;
	while (flag.taille - flag.moins > 0)
	{
		if (flag.zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(flag.taille)--;
		size++;
	}
	return (size);
}
