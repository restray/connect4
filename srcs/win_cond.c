/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_cond.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:25:43 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 11:46:20 by tbelhomm         ###   ########.fr       */
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

int ft_is_party_finished(t_connect4 *setup)
{
    if (ft_is_grid_filled(setup))
        return 3;
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
