/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:44:24 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 05:45:26 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

int		ft_is_action_up(int **tab, int dim)
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
			if (tab[i][j] == 0 && tab[i + 1][j] > 0)
				return (1);
		}
	}
	return (0);
}

void	ft_fuse_up(int **tab, int dim)
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
				if (i - 1 <= 0 || tab[i - 1][j] != tmp)
				{
					tab[i][j] = tmp * 2;
					tab[i + 1][j] = 0;
				}
			}
		}
	}
}

void	ft_moove_up(int **tab, int dim)
{
	int		i;
	int		j;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim - 1)
		{
			if (tab[i][j] == 0 && tab[i + 1][j] > 0)
			{
				tab[i][j] = tab[i + 1][j];
				tab[i + 1][j] = 0;
			}
		}
	}
}

int		ft_up_keys(int **tab, int dim)
{
	int		i;

	i = dim;
	while (i--)
		ft_moove_up(tab, dim);
	ft_fuse_up(tab, dim);
	ft_moove_up(tab, dim);
	i = dim;
	while (i >= 2)
	{
		i /= 3;
		ft_generate(tab, dim);
	}
	return (1);
}
