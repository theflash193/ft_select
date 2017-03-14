/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_gesture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:18:19 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/14 16:18:22 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	clst_iter_custom(t_clst *alst, void (*f)(t_clst *), int fd)
{
	t_clst *cursor;
	t_select	*elem;
	int			retour_chariot;

	retour_chariot = 0;
	cursor = alst;
	if (cursor == NULL)
		return ;
	elem = (t_select *)cursor->content;
	if (elem->selected == 1)
	{
		ft_putstr_fd(elem->content, fd);
		ft_putchar_fd(' ', fd);
		retour_chariot = 1;
	}
	while (cursor->next != alst && cursor != NULL)
	{
		cursor = cursor->next;
		elem = (t_select *)cursor->content;
		if (elem->selected == 1)
		{
			ft_putstr_fd(elem->content, fd);
			ft_putchar_fd(' ', fd);
			retour_chariot = 1;
		}
	}
	if (retour_chariot)
		ft_putchar_fd('\n', 1);
}

void	affichage_terminal(t_clst *cursor)
{
	t_select	*elem;

	elem = (t_select *)cursor->content;
	if (elem->selected == 1)
		ft_putstr(elem->content);
}

void	event_return(t_env *e)
{
	clear_window();
	normal_cursor();
	clst_iter_custom(e->liste_selection, affichage_terminal, 1);
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", 1);
	clear_env(e);
}

int 	event_gesture(t_env *e, char *s)
{
	if (s[0] == 27 && s[1] == 0 && s[2] == 0)
	{
		reset_terminal();
		return (-1);
	}
	if (s[0] == 27 && s[1] == 91 && s[2] == 68)
		event_left(e);
	if (s[0] == 27 && s[1] == 91 && s[2] == 67)
		event_right(e);
	if (s[0] == 32 && s[1] == 0 && s[2] == 0)
		event_select(e);
	if (s[0] == 10 && s[1] == 0 && s[2] == 0)
	{
		event_return(e);
		return (-1);
	}
	if ((s[0] == 127 && s[1] == 0 && s[2] == 0) || (s[0] == 27 && s[1] == 91 && s[2] == 51))
	{
		event_delete(e);
		if (e->nombre_argument == 0)
		  {
		 	reset_terminal();
			return (-1);
		  }
	}
	return (0);
}
