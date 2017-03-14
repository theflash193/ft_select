/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:23:06 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/14 18:23:09 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int 	set_terminal(t_env *e)
{
	struct termios p;

	if ((e->term_type = getenv("TERM")) == NULL)
		return (-1);
	if ((tgetent(NULL, e->term_type)) == 0)
		return (-1);
	e->termios = (struct termios *)malloc(sizeof(struct termios));
	if (tcgetattr(0, &p) == -1)
	{
		putendl_fd("fail to get termios", e->tty_out);
		return (-1);
	}
	if ((e->default_termios = (struct termios *)malloc(sizeof(struct termios))) == NULL)
		return (-1);
	ft_memcpy(e->default_termios, &p, sizeof(struct termios));
	p.c_lflag &= ~(ICANON);
	p.c_lflag &= ~(ECHO);
	p.c_cc[VMIN] = 1;
	p.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &p) == -1)
		return (-1);
	ft_memcpy(e->termios, &p, sizeof(struct termios));
	return(0);
}

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
