/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:48:35 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/02 19:05:21 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_flag(t_flags flag, va_list arg_list)
{
	int		size;

	size = 0;
	if (flag.type == 'c')
		size = ft_display_flag_c(va_arg(arg_list, int), flag);
	else if (flag.type == 's')
		size = ft_display_flag_s(va_arg(arg_list, char *), flag);
	else if (flag.type == 'p')
		size = ft_display_flag_p(va_arg(arg_list, unsigned long long), flag);
	else if (flag.type == '%')
		size = ft_display_flag_pourcentage(flag);
	else if (flag.type == 'i' || flag.type == 'd')
		size = ft_display_flag_integer(va_arg(arg_list, int), flag);
	else if (flag.type == 'u')
		size = ft_display_flag_unsigned_int(va_arg(arg_list, unsigned int),
				flag);
	else if (flag.type == 'x' || flag.type == 'X')
		size = ft_display_flag_hex(va_arg(arg_list, unsigned int),
				flag.type == 'x' ? 0 : 1, flag);
	return (size);
}

int		ft_traitement(char *string, va_list arg_list)
{
	unsigned int	i;
	int				size;
	t_flags			flag;

	i = 0;
	size = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%' && string[i + 1])
		{
			++i;
			flag = ft_create_flag();
			ft_parse_flag(string, &i, &flag, arg_list);
			if (ft_flag_exist(string[i]))
				size += ft_display_flag(flag, arg_list);
			else
				size += ft_putchar(string[i]);
		}
		else
			size += ft_putchar(string[i]);
		i++;
	}
	return (size);
}

int		ft_printf(const char *args, ...)
{
	va_list		arg_list;
	int			printed_chars;
	char		*string;

	string = ft_strdup(args);
	va_start(arg_list, args);
	printed_chars = ft_traitement(string, arg_list);
	va_end(arg_list);
	free(string);
	return (printed_chars);
}
