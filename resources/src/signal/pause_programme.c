/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_programme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:59:44 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:01:25 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	pause_programme(int i)
{
	t_env	*e;
	char	cp[1];

	e = singleton();
	cp[0] = e->default_termios->c_cc[VSUSP];
	clear_window();
	normal_cursor();
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", e->tty_out);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}
