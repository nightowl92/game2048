/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:18:11 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 06:28:48 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

static void		ft_box(int x, int y, int putsp, int putnl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < putnl - 1)
	{
		j = -1;
		while (++j < putsp - 1)
		{
			mvprintw(y * putnl + i, x * putsp + j, " ");
		}
	}
}

static void		set_colors(void)
{
	init_pair(1, COLOR_YELLOW, COLOR_GREEN);
	init_pair(2, COLOR_GREEN, COLOR_YELLOW);
	init_pair(3, COLOR_CYAN, COLOR_WHITE);
	init_pair(4, COLOR_WHITE, COLOR_CYAN);
	init_pair(5, COLOR_MAGENTA, COLOR_RED);
	init_pair(6, COLOR_RED, COLOR_MAGENTA);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_WHITE, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_BLUE);
}

static int		get_color(int **in, int x, int y, int putsp[2])
{
	int	empty;
	int cp;
	int i;

	i = 0;
	cp = in[y][x];
	while ((cp /= 2) > 0)
		++i;
	empty = 1;
	if (i > 0)
		color_set(i, NULL);
	else
	{
		empty = 0;
		color_set(11, NULL);
	}
	ft_box(x, y, putsp[0], putsp[1]);
	return (empty);
}

static int		ft_makeshort(int x[2], int putsp[2], int *youwin, int dim)
{
	x[1] = -1;
	*youwin = 0;
	putsp[0] = COLS / dim;
	putsp[1] = LINES / dim;
	start_color();
	if (initscr() == NULL)
		return (0);
	clear();
	set_colors();
	curs_set(FALSE);
	return (1);
}

void			printgraph(int **in, int dim)
{
	int				x[2];
	int				putsp[2];
	int				youwin;

	if (!ft_makeshort(x, putsp, &youwin, dim))
		return ;
	while (++x[1] < dim)
	{
		x[0] = -1;
		while (++x[0] < dim)
		{
			if (in[x[1]][x[0]] >= WIN_VALUE)
				youwin = 1;
			if (putsp[0] > 1 && putsp[1] > 1)
			{
				if (get_color(in, x[0], x[1], putsp))
					ft_numinbox(x, putsp, in);
				if (youwin)
					mvprintw(x[1] * putsp[1] \
							+ putsp[1], x[0] * putsp[0], "YOU WIN!!");
			}
		}
	}
	refresh();
}
