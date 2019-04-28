/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:26:11 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 18:14:06 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

static void		ft_free(void)
{
	int		i;

	i = -1;
	while (++i < g_dim)
		free(g_tab[i]);
	free(g_tab);
}

void			ft_lose(void)
{
	int		x;
	int		y;
	char	buffer[3];

	x = 0;
	y = 0;
	color_set(11, NULL);
	mvprintw(LINES / 2, COLS / 2 - 24, LOSE1);
	mvprintw(LINES / 2 + 1, COLS / 2 - 24, LOSE2);
	mvprintw(LINES / 2 + 2, COLS / 2 - 24, LOSE3);
	mvprintw(LINES / 2 + 3, COLS / 2 - 24, LOSE4);
	refresh();
	read(0, buffer, 3);
	ft_free();
	endwin();
	ft_decatchsign();
}
