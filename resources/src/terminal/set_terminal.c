/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_terminal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:54:36 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 15:55:49 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		set_terminal(t_env *e)
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
	if ((e->default_termios = (struct termios *)malloc(sizeof(struct termios)))
			== NULL)
		return (-1);
	ft_memcpy(e->default_termios, &p, sizeof(struct termios));
	p.c_lflag &= ~(ICANON);
	p.c_lflag &= ~(ECHO);
	p.c_cc[VMIN] = 1;
	p.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &p) == -1)
		return (-1);
	ft_memcpy(e->termios, &p, sizeof(struct termios));
	return (0);
}
