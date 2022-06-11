/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:35:31 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 11:04:59 by aweaver          ###   ########.fr       */
/*   Updated: 2022/06/11 10:49:04 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

#ifndef CONNECT4_H
# define CONNECT4_H
# define MIN_LINES 6
# define MIN_COLUMNS 7
# include <stdbool.h>
# include "ft_printf.h"

# define CELL_ENNEMY 2
# define CELL_FRIEND 1
# define CELL_EMPTY 0

# define CELL_CHAR_ENNEMY 'x'
# define CELL_CHAR_FRIEND 'o'
# define CELL_CHAR_EMPTY ' '

typedef struct  s_connect4 {
    int         lines;
    int         columns;
    int**       grid;
}               t_connect4;

void    *ft_free(void *addr);
int     ft_allocate_grid(t_connect4 *setup);
void    ft_deallocate_grid(t_connect4 *setup);
void    ft_display_grid(t_connect4 *setup);
int		ft_get_first_player(void);
int     ft_ia_play(t_connect4 *setup);

#endif
