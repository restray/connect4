/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:29:16 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 18:58:09 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int ft_can_win_in_round(t_connect4 *setup, int n, int player_type)
{
	if (n < 0)
		return (-1);
	for (int col = 0; col < setup->columns; col++)
	{
		if (!ft_is_column_fullfilled(setup, col))
		{
			int line = ft_add_pawn(setup, col, player_type);
			if (ft_is_party_finished(setup))
			{
				setup->grid[line][col] = CELL_EMPTY;
				return col;
			}
			int res = ft_can_win_in_round(setup, n - 1, player_type);
			setup->grid[line][col] = CELL_EMPTY;
			if (res >= 0)
				return res;
		}
	}
	return -1;
}

int ft_ia_compute(t_connect4 *setup)
{
	int column;

	for (int i = 1; i <= 3; i++) {
		column = ft_can_win_in_round(setup, i, CELL_IA);
		if (column >= 0)
			return column;

		if (i == 1) {
			column = ft_can_win_in_round(setup, i, CELL_PLAYER);
			if (column >= 0)
				return column;
		}
	}

	return rand() % setup->columns;
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
