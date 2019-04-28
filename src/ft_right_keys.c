/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:41:13 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 07:05:43 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

int		ft_is_action_right(int **tab, int dim)
{
	int		i;
	int		j;
	int		tmp;

	j = -1;
	while (++j < dim - 1)
	{
		i = -1;
		while (++i < dim)
		{
			tmp = tab[i][j];
			if (tab[i][j] == tmp && tab[i][j + 1] == tmp && tmp != 0)
				return (1);
			if (tab[i][j] > 0 && tab[i][j + 1] == 0)
				return (1);
		}
	}
	return (0);
}

void	ft_fuse_right(int **tab, int dim)
{
	int		i;
	int		j;
	int		tmp;

	j = -1;
	while (++j < dim - 1)
	{
		i = -1;
		while (++i < dim)
		{
			tmp = tab[i][j];
			if (tab[i][j] == tmp && tab[i][j + 1] == tmp)
			{
				if (tab[i][j + 2] != tmp)
				{
					tab[i][j + 1] = tmp * 2;
					tab[i][j] = 0;
				}
			}
		}
	}
}

void	ft_moove_right(int **tab, int dim)
{
	int		i;
	int		j;

	j = -1;
	while (++j < dim - 1)
	{
		i = -1;
		while (++i < dim)
		{
			if (tab[i][j] > 0 && tab[i][j + 1] == 0)
			{
				tab[i][j + 1] = tab[i][j];
				tab[i][j] = 0;
			}
		}
	}
}

int		ft_right_keys(int **tab, int dim)
{
	int		i;

	i = dim;
	while (i--)
		ft_moove_right(tab, dim);
	ft_fuse_right(tab, dim);
	ft_moove_right(tab, dim);
	i = dim;
	while (i >= 2)
	{
		i /= 3;
		ft_generate(tab, dim);
	}
	return (1);
}
