/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:06:17 by tbelhomm          #+#    #+#             */
/*   Updated: 2020/12/02 19:07:18 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_flags
{
	int	type;
	int etoile;
	int	etoileneg;
	int point;
	int moins;
	int zero;
	int taille;
}				t_flags;

int				ft_printf(const char *format, ...);

int				ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_putstr_len(char *s, size_t len);
int				ft_putchar_size(int zero, int size);
int				ft_putspace_int(int taille, int longueur, int zero);

t_flags			ft_create_flag(void);
void			ft_flag_moins(t_flags *flag);
void			ft_flag_etoile(t_flags *flag, va_list arg_list);
void			ft_flag_point(char *string,
				unsigned int *i, t_flags *flag, va_list arg_list);
void			ft_flag_digit(t_flags *flag, char c);

int				ft_flag_exist(char c);
int				ft_flag_option_exist(char c);
void			ft_parse_flag(char *string, unsigned int *i,
						t_flags *flag, va_list arg_list);
int				ft_display_flag_option_taille(t_flags flag);

int				ft_display_flag_c(int c, t_flags flag);

int				ft_display_flag_s(char *s, t_flags flag);

int				ft_display_flag_p(unsigned long long p, t_flags flag);

int				ft_display_flag_pourcentage(t_flags flag);

int				ft_display_flag_unsigned_int(unsigned int number,
											t_flags flag);
int				ft_display_flag_hex(unsigned int number,
						int minuscule, t_flags flag);

int				ft_display_flag_hex(unsigned int number, int minuscule,
								t_flags flag);

int				ft_display_flag_integer(int number, t_flags flag);
#endif
