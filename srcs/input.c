/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:38:08 by aweaver           #+#    #+#             */
/*   Updated: 2022/06/11 23:34:53 by tbelhomm         ###   ########.fr       */
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

int ft_prompt_col(int first_player)
{
    ft_printf("%s > ", (first_player == 0 ? CELL_CHAR_ENNEMY : CELL_CHAR_IA));
    char str[100];
    ft_memset(str, 0, sizeof(char) * 100);
    int i = 0;
    char c;
    bool is_valid = false;
    int ret;
    while ((ret = read(STDIN_FILENO, &c, 1)) == 1)
    {
        if (ft_isdigit(c) && i < 8)
        {
            is_valid = (i == 0 ? true : is_valid);
            str[i] = c;
        }
        else if (c == '\n')
        {
            break;
        }
        else
        {
            is_valid = false;
        }
        i++;
    }
    if (ret <= 0)
        return (-2);
    if (!is_valid)
        return (-1);
    return ft_atoi_err(str);
}
