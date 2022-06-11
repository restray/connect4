/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:04:42 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 17:34:21 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int    ft_allocate_grid(t_connect4 *setup)
{
	setup->grid = malloc(sizeof(int *) * (setup->lines + 1));
	if (!(setup->grid))
	{
		ft_printf("Mayday!! It seems we have an important issue captain!!\n");
		return (1);
	}
	ft_memset(setup->grid, 0, sizeof(int *) * (setup->lines + 1));

	int i = 0;
	while (i < setup->lines)
	{
		setup->grid[i] = malloc(sizeof(int) * (setup->columns + 1));
		if (!(setup->grid[i]))
		{
			ft_printf("Mayday!! It seems we have an important issue captain, we can't make a column?!\n");
			return (1);
		}
		ft_memset(setup->grid[i], 0, sizeof(int) * (setup->columns + 1));
		i++;
	}

	return (0);
}

void    ft_deallocate_grid(t_connect4 *setup)
{
	int i = 0;
	while (i < setup->lines)
		free(setup->grid[i++]);
	free(setup->grid);
}

static void ft_get_color_winner(int round, int winner)
{
	NOCOLOUR();
	ft_printf("%s", GREY);
	if (winner == 2)
		ft_printf("%s", ((round == 0) ? YELLOW : RED));
	if (winner == 1)
		ft_printf("%s", ((round == 1) ? RED : YELLOW));
}

void    ft_display_grid(t_connect4 *setup, int round, int winner)
{
	ft_printf("%s", CLEAR);
	// ///////////////////
	ft_get_color_winner(round, winner);
	for (int y = 0; y < (setup->columns * 2) + 2; y++)
	{
		if (y == 0)
			ft_printf("%s", GRID_TOP_LEFT);
		else if (y == (setup->columns * 2) + 1)
			ft_printf("%s", GRID_TOP_RIGHT);
		else
			ft_printf("%s", GRID_TOP_BOTTOM);
	}
	NOCOLOUR();
	for (int i = setup->lines - 1; i >= 0; i--)
	{
		int bg_i = i % 2;
		NOCOLOUR();
		ft_putchar('\n');
		// ///////////////////
		ft_get_color_winner(round, winner);
		ft_printf("%s", GRID_LEFT_RIGHT);
		NOCOLOUR();
		for (int y = 0; y < setup->columns; y++)
		{
			if (bg_i++ % 2 == 0)
				ft_printf("%s", B_GREY);
			else
				NOCOLOUR();
			if (setup->grid[i][y] == CELL_EMPTY)
				ft_printf("%s", CELL_CHAR_EMPTY);
			else if (setup->grid[i][y] == CELL_IA)
				ft_printf("%s", ((round == 0) ? CELL_CHAR_IA : CELL_CHAR_ENNEMY));
			else if (setup->grid[i][y] == CELL_PLAYER)
				ft_printf("%s", ((round == 0) ? CELL_CHAR_ENNEMY : CELL_CHAR_IA));
			else
				ft_printf("Gone wrong... %i\n", setup->grid[i][y]);
		}
		// ///////////////////
		NOCOLOUR();
		ft_get_color_winner(round, winner);
		ft_printf("%s", GRID_LEFT_RIGHT);
		NOCOLOUR();
	}
	ft_putchar('\n');
	ft_get_color_winner(round, winner);
	// ///////////////////
	for (int y = 0; y < (setup->columns * 2) + 2; y++)
	{		
		if (y == 0)
			ft_printf(GRID_BOTTOM_LEFT);
		else if (y == (setup->columns * 2) + 1)
			ft_printf(GRID_BOTTOM_RIGHT);
		else
			ft_printf(GRID_TOP_BOTTOM);
	}
	NOCOLOUR();
	ft_printf("\n\n");
}
