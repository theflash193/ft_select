/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:27:50 by grass-kw          #+#    #+#             */
/*   Updated: 2017/02/28 23:28:52 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	selected(t_env *e)
{
	t_select	*current;
	t_select	*tmp;
	t_clst		*next;

	current = e->current_elem->content;
	current->selected = 1;
	if ((next = find_next(e->current_elem)) != NULL)
	{
		tmp = (t_select *)next->content;
		tmp->current = 1;
		current->current = 0;
		e->current_elem = next;
	}
}

void	disable_seleted(t_env *e)
{
	t_select	*current;

	current = e->current_elem->content;
	current->selected = 0;
}

t_clst	*find_next(t_clst *alst)
{
	t_clst 		*cursor;
	t_select	*elem;

	cursor = alst;
	if (cursor == NULL)
		return (NULL);
	cursor = cursor->next;
	elem = (t_select *)cursor->content;
	while (cursor->next != alst && cursor != NULL)
	{
		elem = (t_select *)cursor->content;
		if (elem->current == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
