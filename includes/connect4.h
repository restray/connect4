/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:35:31 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 14:46:09 by aweaver          ###   ########.fr       */
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

# define CELL_PLAYER 2
# define CELL_IA 1
# define CELL_EMPTY 0

# define RED "\33[1;31m"
# define YELLOW "\33[1;33m"
# define NOCOLOUR "\33[m"
# define CLEAR "\033[1;1H\033[2J"
# define CELL_CHAR_ENNEMY "※"
# define CELL_CHAR_IA "⁜"
# define CELL_CHAR_EMPTY ' '

#define IA 0
#define PLAYER 1

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
bool    ft_is_column_fullfilled(t_connect4 *setup, int column);
int     ft_is_party_finished(t_connect4 *setup);
int     ft_add_pawn(t_connect4 *setup, int column, int player_type);
bool    ft_is_grid_empty(t_connect4 *setup);
bool    ft_is_grid_filled(t_connect4 *setup);

#endif
