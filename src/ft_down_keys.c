/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:44:03 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 05:44:18 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

int		ft_is_action_down(int **tab, int dim)
{
	int		i;
	int		j;
	int		tmp;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim - 1)
		{
			tmp = tab[i][j];
			if (tab[i][j] == tmp && tab[i + 1][j] == tmp && tmp != 0)
				return (1);
			if (tab[i][j] > 0 && tab[i + 1][j] == 0)
				return (1);
		}
	}
	return (0);
}

void	ft_fuse_down(int **tab, int dim)
{
	int		i;
	int		j;
	int		tmp;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim - 1)
		{
			tmp = tab[i][j];
			if (tab[i][j] == tmp && tab[i + 1][j] == tmp)
			{
				if (i + 2 >= dim || tab[i + 2][j] != tmp)
				{
					tab[i + 1][j] = tmp * 2;
					tab[i][j] = 0;
				}
			}
		}
	}
}

void	ft_moove_down(int **tab, int dim)
{
	int		i;
	int		j;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim - 1)
		{
			if (tab[i][j] > 0 && tab[i + 1][j] == 0)
			{
				tab[i + 1][j] = tab[i][j];
				tab[i][j] = 0;
			}
		}
	}
}

int		ft_down_keys(int **tab, int dim)
{
	int i;

	i = dim;
	while (i--)
		ft_moove_down(tab, dim);
	ft_fuse_down(tab, dim);
	ft_moove_down(tab, dim);
	i = dim;
	while (i >= 2)
	{
		i /= 3;
		ft_generate(tab, dim);
	}
	return (1);
}
