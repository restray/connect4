/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:48:09 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/02 18:48:11 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_create_flag(void)
{
	t_flags	flag;

	flag.type = 0;
	flag.moins = 0;
	flag.etoile = 0;
	flag.point = -1;
	flag.taille = 0;
	flag.etoileneg = 0;
	return (flag);
}

void	ft_flag_moins(t_flags *flag)
{
	(*flag).moins = 1;
	(*flag).zero = 0;
}

void	ft_flag_etoile(t_flags *flag, va_list arg_list)
{
	(*flag).etoile = 1;
	(*flag).taille = va_arg(arg_list, int);
	if ((*flag).taille < 0)
	{
		(*flag).moins = 1;
		(*flag).etoileneg = 1;
		(*flag).taille *= -1;
	}
	else
		(*flag).etoileneg = 0;
}

void	ft_flag_point(char *string,
			unsigned int *i, t_flags *flag, va_list arg_list)
{
	if (string[++(*i)] == '*')
	{
		(*flag).point = va_arg(arg_list, int);
		(*i)++;
	}
	else
	{
		(*flag).point = 0;
		while (ft_isdigit(string[*i]))
			(*flag).point = ((*flag).point * 10) + (string[(*i)++] - '0');
	}
}

void	ft_flag_digit(t_flags *flag, char c)
{
	if ((*flag).etoile == 1)
		(*flag).taille = 0;
	(*flag).taille = ((*flag).taille * 10) + (c - '0');
}
