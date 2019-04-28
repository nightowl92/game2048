/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:51:12 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 06:07:05 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

static void			print_button(int bouton1, int bouton2)
{
	if (bouton1 == 0)
	{
		color_set(1, NULL);
		mvprintw(10, 20, "NEW GAME");
	}
	else
	{
		color_set(2, NULL);
		mvprintw(10, 20, "->NEW GAME");
	}
	if (bouton2 == 0)
	{
		color_set(1, NULL);
		mvprintw(14, 20, "EXIT");
	}
	else
	{
		color_set(2, NULL);
		mvprintw(14, 20, "->EXIT");
	}
}

void				ft_printmenu(int bouton1, int bouton2)
{
	clear();
	color_set(1, NULL);
	mvprintw(0, 0, " ___ ___ ___ ___      _                          ");
	mvprintw(1, 0, "|_  |   | | | . |   _| |___    ___ ___ _____ ___ ");
	mvprintw(2, 0, "|  _| | |_  | . |  | . | .'|  | . | .'|     | -_|");
	mvprintw(3, 0, "|___|___| |_|___|  |___|__,|  |_  |__,|_|_|_|___|");
	mvprintw(4, 0, "                              |___|              ");
	print_button(bouton1, bouton2);
	color_set(1, NULL);
	mvprintw(5, 27, "by mgazel & stherkil");
}

static void			ft_decision_menu(char buffer[6], int *b1, int *b2, int *dim)
{
	if (buffer[0] == 27 && buffer[1] == 91 && (buffer[2] == 67 ||\
				buffer[2] == 68 || buffer[2] == 66 || buffer[2] == 65))
	{
		if (*b1 == 1)
			*b1 = 0;
		else
			*b1 = 1;
		if (*b2 == 1)
			*b2 = 0;
		else
			*b2 = 1;
	}
	if (buffer[0] == 43)
		if (*dim < 21)
			*dim = *dim + 1;
	if (buffer[0] == 45)
		if (*dim > 2)
			*dim = *dim - 1;
	if (buffer[0] == 27 && buffer[1] == 0)
		ft_exit();
}

static int			init_menu(int *bouton1, int *bouton2, int *dim)
{
	*bouton1 = 1;
	*bouton2 = 0;
	*dim = 4;
	if (initscr() == NULL)
		return (-1);
	start_color();
	curs_set(FALSE);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	return (1);
}

int					ft_menu(void)
{
	int		bouton1;
	int		bouton2;
	int		dim;
	char	buffer[3];

	if (init_menu(&bouton1, &bouton2, &dim) == -1)
		return (-1);
	while (1)
	{
		put_menu(bouton1, bouton2, dim);
		ft_memset(buffer, '\0', 3);
		read(0, buffer, 3);
		ft_decision_menu(buffer, &bouton1, &bouton2, &dim);
		if (buffer[0] == 13 && bouton1 == 1)
			break ;
		if (buffer[0] == 13 && bouton2 == 1)
			ft_exit();
	}
	endwin();
	return (dim);
}
