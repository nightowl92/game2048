/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:21:16 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 05:21:50 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

int		ft_decision(char buffer[6], int **tab, int dim)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
		if (ft_is_action_up(tab, dim) == 1)
			ft_up_keys(tab, dim);
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
		if (ft_is_action_down(tab, dim) == 1)
			ft_down_keys(tab, dim);
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
		if (ft_is_action_right(tab, dim) == 1)
			ft_right_keys(tab, dim);
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
		if (ft_is_action_left(tab, dim) == 1)
			ft_left_keys(tab, dim);
	if (buffer[0] == 27 && buffer[1] == 0)
		ft_ctrl_c(0);
	if (!ft_is_action_up(tab, dim) && !ft_is_action_down(tab, dim)\
			&& !ft_is_action_right(tab, dim) && !ft_is_action_left(tab, dim))
		return (0);
	return (1);
}
