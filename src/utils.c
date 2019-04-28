/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 03:20:40 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 18:13:46 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

void		ft_exit(void)
{
	endwin();
	ft_putstr(tgetstr("ve", NULL));
	ft_putstr(tgetstr("cl", NULL));
	exit(1);
}

static int	ft_dims(int dim)
{
	if (dim / 3 == 0)
		return (1);
	else
		return (dim / 3);
}

void		printpop(int dim)
{
	char *tmp;

	if ((tmp = ft_itoa(ft_dims(dim))))
	{
		mvprintw(21, 41, tmp);
		free(tmp);
	}
}

int			ft_numinbox(int x[2], int putsp[2], int **in)
{
	char	*tmp;

	if (ft_strlen(tmp = ft_itoa(in[x[1]][x[0]])))
	{
		mvprintw(x[1] * putsp[1] + putsp[1] / 2,\
				x[0] * putsp[0] + putsp[0] / 2, tmp);
		free(tmp);
		return (1);
	}
	else
		return (0);
}

int			**init_tab(int dim)
{
	int		i;
	int		j;
	int		**tab;

	i = -1;
	if (!(tab = (int **)malloc(sizeof(int *) * (dim + 1))))
		return (NULL);
	while (++i < dim)
		tab[i] = (int *)malloc(sizeof(int) * (dim + 1));
	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
			tab[i][j] = 0;
	}
	return (tab);
}
