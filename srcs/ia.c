/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:29:16 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/12 22:12:49 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int ft_can_win_in_round(t_connect4 *setup, int n, int player_type, int start_pos)
{
	if (n <= 0 || start_pos >= setup->columns)
		return (-1);
	for (int col = start_pos; col < setup->columns; col++)
	{
		if (!ft_is_column_fullfilled(setup, col))
		{
			int line = ft_add_pawn(setup, col, player_type);
			if (ft_is_party_finished(setup) == player_type)
			{
				setup->grid[line][col] = CELL_EMPTY;
				return col;
			}
			else
			{
				int res = ft_can_win_in_round(setup, n - 1, player_type, start_pos);
				setup->grid[line][col] = CELL_EMPTY;
				if (res >= 0)
					return res;
			}
		}
	}
	return -1;
}

static int ft_has_impact(t_connect4 *setup, int column, int tries)
{
	// Protection against bad column nb
	if (!(column >= 0 && column < setup->columns))
		return (-1);

	int line = ft_add_pawn(setup, column, CELL_IA);
	while (ft_can_win_in_round(setup, 1, CELL_PLAYER, 0) >= 0 && column >= 0 && column < setup->columns)
	{
		setup->grid[line][column] = CELL_EMPTY;
		column = ft_can_win_in_round(setup, tries, CELL_IA, column + 1);
		if (column == -1)
			return (-1);
		line = ft_add_pawn(setup, column, CELL_IA);
	}
	setup->grid[line][column] = CELL_EMPTY;
	return column;
}

int ft_ia_compute(t_connect4 *setup)
{
	int column;

	column = ft_can_win_in_round(setup, 1, CELL_IA, 0);
	if (column >= 0)
		return column;

	column = ft_can_win_in_round(setup, 1, CELL_PLAYER, 0);
	if (column >= 0)
		return column;

	column = ft_can_win_in_round(setup, 2, CELL_IA, 0);
	if (column >= 0 && (column = ft_has_impact(setup, column, 2)) < setup->columns && column >= 0)
		return column;
		
	column = ft_can_win_in_round(setup, 2, CELL_PLAYER, 0);
	if (column >= 0 && (column = ft_has_impact(setup, column, 2)) < setup->columns && column >= 0)
		return column;

	column = ft_can_win_in_round(setup, 3, CELL_IA, 0);
	if (column >= 0 && (column = ft_has_impact(setup, column, 3)) < setup->columns && column >= 0)
		return column;

	if (setup->last_column_played == -1)
		return setup->columns / 2;

	for (int i = 0; i < setup->columns; i++)
	{
		if (!ft_is_column_fullfilled(setup, i)) {
			column = ft_has_impact(setup, i, 1);
			if (column >= 0 && column < setup->columns)
				return column;
		}
	}
	return setup->columns / 2;
}

int ft_ia_play(t_connect4 *setup)
{
	int column = -1;

	if (!ft_is_grid_empty(setup))
		column = ft_ia_compute(setup);
	else
		column = setup->columns / 2;
	return column;
}
