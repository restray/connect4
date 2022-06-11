/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:29:16 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 11:17:00 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static bool ft_is_column_fullfilled(t_connect4 *setup, int column)
{
    if (setup->grid[setup->lines - 1][column] != CELL_EMPTY)
        return true;
    return false;
}

static bool ft_is_grid_empty(t_connect4 *setup)
{
    for (int i = 0; i < setup->columns; i++) {
        if (setup->grid[0][i] != CELL_EMPTY)
            return false;
    }
    return true;
}

static int ft_is_4_in_line(t_connect4 *setup, int line, int column)
{
    int player_type = setup->grid[line][column];
    int i = 0;
    while (i < 4 && line + i < setup->lines)
    {
        if (setup->grid[line + i][column] != player_type)
            return CELL_EMPTY;
        i++;
    }
    if (i != 4)
        return CELL_EMPTY;
    return player_type;
}

static int ft_is_4_in_col(t_connect4 *setup, int line, int column)
{
    int player_type = setup->grid[line][column];
    int i = 0;
    
    while (i < 4 && column + i < setup->columns)
    {
        if (setup->grid[line][column + i] != player_type)
            return CELL_EMPTY;
        i++;
    }
    if (i != 4)
        return CELL_EMPTY;
    return player_type;
}

static int ft_is_4_in_diag(t_connect4 *setup, int line, int column, bool left)
{
    int player_type = setup->grid[line][column];
    int i = 0, y = 0;

    while (i < 4 && line + i < setup->lines && column + y >= 0 && column + y < setup->columns)
    {
        if (setup->grid[line + i][column + y] != player_type)
            return CELL_EMPTY;
        i++;
        if (left)
            y--;
        else
            y++;
    }
    if (i != 4)
        return CELL_EMPTY;
    return player_type;
}

static int ft_is_party_finished(t_connect4 *setup)
{
    for (int i = 0; i < setup->lines - 3; i++)
    {
        for (int y = 0; y < setup->columns - 3; y++)
        {
            if (setup->grid[i][y] != CELL_EMPTY)
            {
                int res = 0;
                if ((res = ft_is_4_in_line(setup, i, y)) != CELL_EMPTY)
                    return res;
                if ((res = ft_is_4_in_col(setup, i, y)) != CELL_EMPTY)
                    return res;
                if ((res = ft_is_4_in_diag(setup, i, y, false)) != CELL_EMPTY)
                    return res;
                if (y >= 3)
                    if ((res = ft_is_4_in_diag(setup, i, y, true)) != CELL_EMPTY)
                        return res;
            }
        }
    }
    return CELL_EMPTY;
}

static int  ft_add_pawn(t_connect4 *setup, int column, int player_type)
{
    for (int i = 0; i < setup->lines; i++) {
        if (setup->grid[i][column] == CELL_EMPTY)
        {
            setup->grid[i][column] = player_type;
            return i;
        }
    }
    return -1;
}

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
        ft_printf("==================================================================\n");
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
            res = ft_ia_backtracking(setup, &col, ((player == CELL_FRIEND) ? CELL_ENNEMY : CELL_FRIEND), player_winning, nb_plays + 1);
            setup->grid[line][i] = CELL_EMPTY;
            if (*player_winning == CELL_FRIEND && res > 0)
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
        nb_plays = ft_ia_backtracking(setup, &column, CELL_FRIEND, &winner, 0);
    else
        column = setup->columns / 2;

    ft_printf("Nb de coups pour gagner %i, %i\n", nb_plays, column);
    return column;
}
