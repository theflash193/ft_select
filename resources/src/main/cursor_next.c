/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 07:15:38 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 09:20:55 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	cursor_next(t_env *e)
{
	t_select	*current;
	t_select	*next;

	current = (t_select *)e->current_elem;
	next = (t_select *)e->current_elem->next;
	current->current = 0;
	next->current = 1;
	e->current_elem = e->current_elem->next;
}
