/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:33:09 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/12 19:30:44 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int ft_display_help_text(void)
{
    ft_printf("Welcome on connect 4 (or LE PUISSANCE 4 in good old French).\n");
    ft_printf("You seem lost. Can I help you? Here is the help guide son:\n");
    ft_printf("\n./connect4 [lines] [columns]\n\n");
    ft_printf("Lines should be at least %i and less than %i\n", MIN_LINES, MAX_LINES);
    ft_printf("Columns should be at least %i and less than %i\n", MIN_COLUMNS, MAX_COLUMNS);

    return (1);
}

int main(int argc, char **argv)
{
    t_connect4 setup;
    int exit = 0;

    if (argc != 3)
        return ft_display_help_text();

    // Check params in
    srand(time(0));
    setup.lines = ft_atoi_err(argv[1]);
    setup.columns = ft_atoi_err(argv[2]);
    setup.last_column_played = -1;
    if (!(setup.lines >= MIN_LINES && setup.lines <= MAX_LINES && setup.columns >= MIN_COLUMNS && setup.columns <= MAX_COLUMNS))
        return ft_display_help_text();

    // Know if we can enter the game
    if (ft_allocate_grid(&setup))
    {
        int round = setup.first_player = ft_get_first_player();
        while (!ft_is_party_finished(&setup))
        {
            if (round % 2 == IA)
            {
                setup.last_column_played = ft_ia_play(&setup);
                ft_add_pawn(&setup, setup.last_column_played, CELL_IA);
            }
            else
            {
                ft_display_grid(&setup, 0);
                int column = -2;
                do {
                    if (column == -1 || column >= setup.columns)
                        ft_printf("Column should be between %i and %i\n", 0, setup.columns - 1);
                    else if (column >= 0)
                        ft_printf("This column is full!\n");
                    column = ft_prompt_col(setup.first_player);
                    if (column == -2)
                    {
                        exit = 1;
                        break;
                    }
                } while (!(column >= 0 && column < setup.columns && !ft_is_column_fullfilled(&setup, column)));
                if (exit == 1)
                    break;
                setup.last_column_played = column;
                ft_add_pawn(&setup, column, CELL_PLAYER);
            }
            round++;
        }
        int winner = ft_is_party_finished(&setup);
        ft_display_grid(&setup, winner);
        if (winner == CELL_IA)
            ft_printf("IA won\n");
        else if (winner == CELL_PLAYER)
            ft_printf("Player won\n");

        ft_deallocate_grid(&setup);
    }

    if (exit == 1)
        ft_printf("Oh, you gave up already? :)\n");

    return (0);
}