/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:44:09 by aweaver           #+#    #+#             */
/*   Updated: 2022/06/11 10:49:24 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	ft_get_first_player(void)
{
	int	first;

	srand(time(0));
	first = (rand() % 2);
	return (first);
}

int main(void)
{
	ft_printf("First = %i\n", ft_get_first_player());
	return (0);
}
