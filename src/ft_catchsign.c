/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catchsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 05:20:48 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 05:49:03 by mgazel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game2048.h"

void	initterm(struct termios *coucou)
{
	(*coucou).c_lflag &= ~(ICANON);
	(*coucou).c_lflag &= ~(ECHO);
	(*coucou).c_cc[VMIN] = 1;
	(*coucou).c_cc[VTIME] = 0;
}

int		check_term(void)
{
	struct termios coucou;

	tcgetattr(0, &coucou);
	initterm(&coucou);
	tcsetattr(0, TCSANOW, &coucou);
	return (1);
}

void	ft_catchsign(void)
{
	signal(SIGWINCH, ft_resize);
	signal(SIGINT, ft_ctrl_c);
}

void	ft_decatchsign(void)
{
	signal(SIGWINCH, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}
