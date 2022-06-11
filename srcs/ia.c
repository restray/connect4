/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:29:16 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 12:11:10 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

/**
 * Compute the next position to play
 *
 * @return int (> 0) The number of plays to do before winning
 * @return int (<= 0) Can't win this way
 */
static int ft_ia_backtracking(t_connect4 *setup, int *column, int player, int *player_winning, int nb_plays)
{
    int res = ft_is_party_finished(setup);
    if (res != CELL_EMPTY)
    {
        *player_winning = res;
        return nb_plays;
    }

    res = -1;
    for (int i = 0; i < setup->columns; i++)
    {
        if (!ft_is_column_fullfilled(setup, i))
        {
            int line = ft_add_pawn(setup, i, player);
            int col = 0;
            res = ft_ia_backtracking(setup, &col, ((player == CELL_IA) ? CELL_PLAYER : CELL_IA), player_winning, nb_plays + 1);
            setup->grid[line][i] = CELL_EMPTY;
            if (*player_winning == CELL_IA && res > 0)
            {
                *column = i;
                return res;
            }
        }
    }
    return res;
}

int ft_ia_play(t_connect4 *setup)
{
    int column = -1, winner = CELL_EMPTY, nb_plays = 1;

    if (!ft_is_grid_empty(setup))
        nb_plays = ft_ia_backtracking(setup, &column, CELL_IA, &winner, 0);
    else
        column = setup->columns / 2;

    ft_printf("Nb de coups pour gagner %i, %i\n", nb_plays, column);
    return column;
}
