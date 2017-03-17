/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:23:06 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/14 18:42:17 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	reset_terminal(void)
{
	t_env *e;

	e = singleton();
	clear_window();
	normal_cursor();
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", 1);
	free_singleton();
}

int		get_terminal_dimension(t_env *e)
{
	struct winsize win_size;

	if (ioctl(0, TIOCGSIZE, &win_size) == -1)
		return (-1);
	e->line = win_size.ws_row;
	e->colonne = win_size.ws_col;
	return (0);
}

int 	configuration_terminal(t_env *e)
{
	refresh_window();
	if (invisible_cursor() == -1)
		return (-1);
	return (0);
}

int		get_tty_name(t_env *e)
{
	char	*tty_out_name;
	int	fd;

	tty_out_name = NULL;
	if ((tty_out_name = ttyname(0)) == NULL)
	{
	    reset_terminal();
	    ft_putendl_fd("ttyname fail", 2);
	    exit(0);
	 }
	if ((e->tty_out = open(tty_out_name, O_WRONLY)) < -1)
	{
	    reset_terminal();
	    ft_putendl_fd("open fail", 2);
	    exit(0);
	}
	return (0);
}
