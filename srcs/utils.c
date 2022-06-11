/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:15:41 by tbelhomm          #+#    #+#             */
/*   Updated: 2022/06/11 23:18:42 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int ft_get_first_player(void)
{
    int first;

    first = (rand() % 2);
    return (first);
}

void    *ft_free(void *addr)
{
    free(addr);
    return (NULL);
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

int ft_get_size_nb(int nb)
{
    int i = 1;
    while (nb /= 10)
        i++;
    return i;
}
