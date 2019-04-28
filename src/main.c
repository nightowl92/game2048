/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:03:20 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 18:38:59 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

static int		init_main(void)
{
	check_term();
	g_dim = ft_menu();
	ft_catchsign();
	if (!(g_tab = init_tab(g_dim)))
		return (0);
	ft_generate(g_tab, g_dim);
	ft_generate(g_tab, g_dim);
	printgraph(g_tab, g_dim);
	return (1);
}

static int		ft_verif(void)
{
	int i;

	i = 2;
	while (i <= WIN_VALUE)
	{
		if (i == WIN_VALUE)
			return (1);
		i *= 2;
	}
	ft_putstr("PLEASE CHOOSE A VALID NUMBER\n");
	return (0);
}

int				main(void)
{
	char	buffer[6];
	int		j;

	if (!ft_verif())
		return (0);
	while (1)
	{
		if (!(init_main()))
			break ;
		while (1)
		{
			ft_memset(buffer, '\0', 6);
			if (read(0, buffer, 6) == -1)
				break ;
			if ((j = ft_decision(buffer, g_tab, g_dim)) == -1)
				break ;
			endwin();
			printgraph(g_tab, g_dim);
			if (j == 0)
				break ;
		}
		ft_lose();
	}
	endwin();
	return (0);
}
