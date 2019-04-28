/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:54:49 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 17:20:10 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

void	put_menu(int bouton1, int bouton2, int dim)
{
	char *tmp;

	ft_printmenu(bouton1, bouton2);
	color_set(1, NULL);
	mvprintw(18, 20, "DIMENSIONS = ");
	if (!(tmp = ft_itoa(dim)))
		return ;
	mvprintw(18, 33, tmp);
	free(tmp);
	printpop(dim);
	mvprintw(21, 20, "NEW POPS EACH TIME: ");
	refresh();
}
