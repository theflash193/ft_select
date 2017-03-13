/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 22:31:40 by grass-kw          #+#    #+#             */
/*   Updated: 2017/02/28 23:18:57 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	changement_taille_fenetre(int i)
{
	t_env *e;

	e = singleton();
	get_terminal_dimension(e);
	clear_window();
	update_maxlen();
	affichage_selection(e);
}

void	pause_programme(int i)
{
	t_env *e;
	char cp[1];


	e = singleton();
	cp[0] =  e->default_termios->c_cc[VSUSP];
	clear_window();
	normal_cursor();
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", e->tty_out);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

void	reprise_programme(int i)
{
	t_env *e;

	e = singleton();
	set_terminal(e);
	configuration_terminal(e);
	update_maxlen();
	affichage_selection(e);
}

void	signal_handler(void)
{
	signal(SIGWINCH, changement_taille_fenetre);
	signal(SIGTSTP, pause_programme);
	signal(SIGCONT, reprise_programme);
}
