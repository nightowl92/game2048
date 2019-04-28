/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:48:03 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 06:30:22 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

void	ft_resize(int aa)
{
	(void)aa;
	endwin();
	printgraph(g_tab, g_dim);
}

void	ft_ctrl_c(int aa)
{
	int i;

	(void)aa;
	i = -1;
	endwin();
	while (++i < g_dim)
		free(g_tab[i]);
	free(g_tab);
	ft_putstr(tgetstr("ve", NULL));
	ft_putstr(tgetstr("cl", NULL));
	exit(1);
}
