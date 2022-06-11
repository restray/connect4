/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_cond.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:25:43 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 18:52:22 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

bool ft_is_column_fullfilled(t_connect4 *setup, int column)
{
    if (setup->grid[setup->lines - 1][column] != CELL_EMPTY)
        return true;
    return false;
}

bool ft_is_grid_empty(t_connect4 *setup)
{
    for (int i = 0; i < setup->columns; i++)
    {
        if (setup->grid[0][i] != CELL_EMPTY)
            return false;
    }
    return true;
}

bool ft_is_grid_filled(t_connect4 *setup)
{
    for (int i = 0; i < setup->columns; i++)
    {
        if (setup->grid[setup->lines - 1][i] == CELL_EMPTY)
            return false;
    }
    return true;
}

static int ft_is_4_in_matrix(t_connect4 *setup, int line, int column, int i_incr, int y_incr)
{
    int player_type = setup->grid[line][column];
    if (player_type == CELL_EMPTY)
        return (CELL_EMPTY);
    int size = 0, i = 0, y = 0;

    while (size < 4
        && line + i >= 0 && line + i < setup->lines
        && column + y >= 0 && column + y < setup->columns)
    {
        if (setup->grid[line + i][column + y] != player_type)
            return CELL_EMPTY;
        i += i_incr;
        y += y_incr;
        size++;
    }
    if (size != 4)
        return CELL_EMPTY;
    return player_type;
}

int ft_is_party_finished(t_connect4 *setup)
{
    if (ft_is_grid_filled(setup))
        return 3;
    for (int i = 0; i < setup->lines; i++)
    {
        for (int y = 0; y < setup->columns; y++)
        {
            if (setup->grid[i][y] != CELL_EMPTY)
            {
                int res = 0;
                // -1
                if ((res = ft_is_4_in_matrix(setup, i, y, -1, -1)) != CELL_EMPTY)
                    return res;
                if ((res = ft_is_4_in_matrix(setup, i, y, -1, 0)) != CELL_EMPTY)
                    return res;
                if ((res = ft_is_4_in_matrix(setup, i, y, -1, 1)) != CELL_EMPTY)
                    return res;
                // 1
                if ((res = ft_is_4_in_matrix(setup, i, y, 1, -1)) != CELL_EMPTY)
                    return res;
                if ((res = ft_is_4_in_matrix(setup, i, y, 1, 0)) != CELL_EMPTY)
                    return res;
                if ((res = ft_is_4_in_matrix(setup, i, y, 1, 1)) != CELL_EMPTY)
                    return res;
                // 0
                if ((res = ft_is_4_in_matrix(setup, i, y, 0, 1)) != CELL_EMPTY)
                    return res;
                if ((res = ft_is_4_in_matrix(setup, i, y, 0, -1)) != CELL_EMPTY)
                    return res;
            }
        }
    }
    return CELL_EMPTY;
}

int ft_add_pawn(t_connect4 *setup, int column, int player_type)
{
    for (int i = 0; i < setup->lines; i++)
    {
        if (setup->grid[i][column] == CELL_EMPTY)
        {
            setup->grid[i][column] = player_type;
            return i;
        }
    }
    return -1;
}
