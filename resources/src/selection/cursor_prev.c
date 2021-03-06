/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_prev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 07:01:34 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 09:21:17 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	cursor_prev(t_env *e)
{
	t_select	*current;
	t_select	*prev;

	current = (t_select *)e->current_elem->content;
	prev = (t_select *)e->current_elem->prev->content;
	current->current = 0;
	prev->current = 1;
	e->current_elem = e->current_elem->prev;
}
