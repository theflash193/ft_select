/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_prev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 07:01:34 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 07:15:31 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	cursor_prev(t_env *e)
{
	t_select	*current;
	t_select	*prev;

	current = (t_select *)e->current;
	prev = (t_select *)e->current->prev;
	current->current = 0;
	prev->current = 1;
	e->current = e->current->prev;
}
