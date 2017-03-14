/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:23:44 by grass-kw          #+#    #+#             */
/*   Updated: 2017/02/28 23:24:41 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	event_quit(t_env *e)
{
	reset_terminal();
}

void	event_left(t_env *e)
{
	cursor_prev(e);
}

void	event_right(t_env *e)
{
	cursor_next(e);
}

void	event_select(t_env *e)
{
	t_select	*current;

	current = e->current_elem->content;
	if (current->selected == 0)
		selected(e);
	else
		disable_seleted(e);
}

void	event_delete(t_env *e)
{
	t_clst		*delete;
	t_select	*tmp;

	if (e->current_elem == e->liste_selection)
		e->liste_selection = e->liste_selection->next;
	delete = e->current_elem;
  	e->current_elem = delete->next;
	tmp = (t_select *)delete->next->content;
	tmp->current = 1;
	clst_del_elem(&delete, delete_selection);
	e->nombre_argument--;
}
