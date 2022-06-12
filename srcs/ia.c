/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:29:16 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/12 18:45:30 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int ft_can_win_in_round(t_connect4 *setup, int n, int player_type, int start_pos)
{
	if (n <= 0)
		return (-1);
	for (int col = start_pos; col < setup->columns; col++)
	{
		if (!ft_is_column_fullfilled(setup, col))
		{
			int line = ft_add_pawn(setup, col, player_type);
			if (ft_is_party_finished(setup))
			{
				setup->grid[line][col] = CELL_EMPTY;
				return col;
			}
			int res = ft_can_win_in_round(setup, n - 1, player_type, 0);
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
		// On essaye de voir si en 2 coup le joueur peut gagner
		if (i == 2)
		{
			// Si il gagne: on bloque sa possibilitée de victoire
			column = ft_can_win_in_round(setup, 1, CELL_PLAYER, 0);
			if (column >= 0)
				return column;
		}

		column = ft_can_win_in_round(setup, i, CELL_IA, 0);
		// Si l'IA peut gagner en i [1 -> 3] tours
		if (column >= 0)
		{
			// Si elle peut gagner en 1 manche
			if (i == 1)
				return column;
			// Si elle peut gagner avec plus d'1 manche
			else
			{
				// On ajoute le pion dans la colonne présentie
				int line = ft_add_pawn(setup, column, CELL_IA);
				// On essaye de voir si le joueur peut gagner en 1 coup
				int column_player = ft_can_win_in_round(setup, 1, CELL_PLAYER, 0);
				// Si le joueur peut gagner
				while (column_player >= 0)
				{
					// On simule d'autres cas dans lesquels notre IA ne fait pas gagner le joueur
					column_player = ft_can_win_in_round(setup, 1, CELL_IA, column_player + 1);
					if (column_player == setup->columns - 1)
					{
						// On retire le pion placé à la ligne 54
						setup->grid[line][column] = CELL_EMPTY;
						return column_player;
					}
				}
				// On retire le pion placé à la ligne 54
				setup->grid[line][column] = CELL_EMPTY;
				return column;
			}
		}

		// On essaye de voir si en 2 coup le joueur peut gagner
		if (i == 1) {
			// Si il gagne: on bloque sa possibilitée de victoire
			column = ft_can_win_in_round(setup, 1, CELL_PLAYER, 0);
			if (column >= 0)
				return column;
		}
	}

	if (setup->last_column_played != -1) {
		if (setup->last_column_played == setup->columns - 1) {
			return setup->last_column_played - 1;
		} else {
			return setup->last_column_played + 1;
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
