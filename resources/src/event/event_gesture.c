/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_gesture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:18:19 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:25:46 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		quit(t_env *e, char *s)
{
	reset_terminal();
	return (-1);
}

int		event_gesture(t_env *e, char *s)
{
	if (s[0] == 27 && s[1] == 0 && s[2] == 0)
		return (quit(e, s));
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
	if ((s[0] == 127 && s[1] == 0 && s[2] == 0) ||
		(s[0] == 27 && s[1] == 91 && s[2] == 51))
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
