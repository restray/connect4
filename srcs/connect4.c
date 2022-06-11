/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:33:09 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 12:10:57 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

/**
 * @brief Ascii to integer function. Handle error and it's sensible to not-digit char.
 * 
 * @param str the input ascii array to convert
 * @return int [>= 0] if the ascii is totally parsed and valid
 * @return int [< 0] if the ascii is invalid
 */
int ft_atoi_err(char *str)
{
    int atoi = 0, i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            atoi = (atoi * 10) + (str[i] - '0');
        else
            return -1;
        i++;
    }
    if (str[i])
        return (-1);
    return atoi;
}

int ft_display_help_text(void)
{
    ft_printf("Welcome on connect 4 (or LE PUISSANCE 4 in good old French).\n");
    ft_printf("You seem lost. Can I help you? Here is the help guide son:\n");
    ft_printf("\n./connect4 [lines] [columns]\n\n");
    ft_printf("Lines should be at least %i\n", MIN_LINES);
    ft_printf("Columns should be at least %i\n", MIN_COLUMNS);

    return (1);
}

int ft_prompt_col()
{
    ft_printf("> ");
    char str[10000];
    ft_memset(str, 0, sizeof(char) * 10000);
    int i = 0;
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && i < 8)
    {
        if (ft_isdigit(c))
            str[i++] = c;
        else if (c == '\n')
            break;
    }
    return ft_atoi_err(str);
}

int main(int argc, char **argv)
{
    t_connect4 setup;

    if (argc != 3)
        return ft_display_help_text();

    setup.lines = ft_atoi_err(argv[1]);
    setup.columns = ft_atoi_err(argv[2]);
    if (!(setup.lines >= MIN_LINES && setup.columns >= MIN_COLUMNS))
        return ft_display_help_text();

    int allocation_ok = ft_allocate_grid(&setup);

    if (allocation_ok == 0) {
        int round = 1; /** @todo random */
        ft_display_grid(&setup);
        while (ft_is_party_finished(&setup) == 0)
        {
            if (round % 2 == IA)
            {
                int column = ft_ia_play(&setup);
                ft_add_pawn(&setup, column, CELL_IA);
            }
            else
            {
                int column = -1;
                do {
                    if (column >= 0)
                        ft_printf("Column should be between %i and %i\n", 0, setup.columns - 1);
                    column = ft_prompt_col();
                } while (!(column >= 0 && column < setup.columns));
                ft_add_pawn(&setup, column, CELL_PLAYER);
            }
            ft_display_grid(&setup);
            round++;
        }
        // --------------------------------------------------------------------------------------------------------------------
        // Here should be the game!
        // --------------------------------------------------------------------------------------------------------------------
    }

    ft_deallocate_grid(&setup);

    return (0);
}