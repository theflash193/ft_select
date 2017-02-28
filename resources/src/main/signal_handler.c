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
}

void	pause_programme(int i)
{
	t_env *e;

	e = singleton();
	clear_window();
	normal_cursor();
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", e->tty_out);
}

void	reprise_programme(int i)
{
	t_env *e;

	e = singleton();
	if (tcsetattr(0, 0, e->termios) == -1)
		putendl_fd("fail to connect termios", e->tty_out);
}

void	signal_handler(void)
{
	signal(SIGWINCH, changement_taille_fenetre);
	signal(SIGTSTP, pause_programme);
	signal(SIGCONT, reprise_programme);
}
