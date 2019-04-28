/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:45:39 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 06:59:28 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

static int			ft_rand_two_or_for(void)
{
	int		random;

	random = rand() % 3;
	if (random == 1 || random == 2)
		random = 2;
	else
		random = 4;
	return (random);
}

static int			cpt_empty_place(int **tab, int dim)
{
	int		i;
	int		j;
	int		cpt;

	i = -1;
	cpt = 0;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			if (tab[i][j] == 0)
				cpt++;
		}
	}
	return (cpt);
}

static int			put_place(int **tab, int rput, int random, int dim)
{
	int		i;
	int		j;
	int		cpt;

	i = -1;
	cpt = 0;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			if (tab[i][j] == 0)
				cpt++;
			if (cpt == rput)
			{
				tab[i][j] = random;
				return (1);
			}
		}
	}
	return (-1);
}

static int			get_random_place(int **tab, int dim)
{
	int cpt;

	cpt = cpt_empty_place(tab, dim);
	if (cpt == 0)
		return (-1);
	return (rand() % cpt);
}

int					ft_generate(int **tab, int dim)
{
	int random;
	int rput;

	random = ft_rand_two_or_for();
	if ((rput = get_random_place(tab, dim)) == 0)
		rput++;
	else if (rput == -1)
		return (-1);
	if (put_place(tab, rput, random, dim) == -1)
		return (-1);
	return (1);
}
