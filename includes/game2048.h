/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2048.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgazel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 06:12:22 by mgazel            #+#    #+#             */
/*   Updated: 2019/04/28 16:52:03 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME2048_H
# define GAME2048_H

# include "libft.h"
# include <termcap.h>
# include <stdlib.h>
# include <unistd.h>
# include <ncurses.h>
# include <termios.h>
# include <sys/ioctl.h>

# define LOSE1 " __  ______  __  __  __   ____  __________"
# define LOSE2 " \\ \\/ / __ \\/ / / / / /  / __ \\/ __/_  __/"
# define LOSE3 "  \\  / /_/ / /_/ / / /__/ /_/ /\\ \\  / /   "
# define LOSE4 "  /_/\\____/\\____/ /____/\\____/___/ /_/    "

enum	e_const
{
	WIN_VALUE = 64
};

int		**g_tab;
int		g_dim;
void	ft_printmenu(int bouton1, int bouton2);
void	put_menu(int bouton1, int bouton2, int dim);
void	ft_exit(void);
void	ft_decatchsign(void);
void	printpop(int dim);
int		ft_numinbox(int x[2], int putsp[2], int **in);
void	ft_lose();
int		ft_generate(int **tab, int dim);
int		ft_decision(char buffer[6], int **tab, int dim);
int		**init_tab(int dim);
void	ft_catchsign(void);
int		check_term(void);
int		ft_up_keys(int **tab, int dim);
int		ft_left_keys(int **tab, int dim);
int		ft_right_keys(int **tab, int dim);
int		ft_down_keys(int **tab, int dim);
int		ft_is_action_up(int **tab, int dim);
int		ft_is_action_right(int **tab, int dim);
int		ft_is_action_left(int **tab, int dim);
int		ft_is_action_down(int **tab, int dim);
void	printgraph(int **in, int dim);
int		ft_menu(void);
void	ft_ctrl_c(int aa);
void	ft_resize(int aa);
#endif
