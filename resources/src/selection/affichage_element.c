/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:09:40 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:09:40 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	affichage_element(t_select *elem)
{
	t_env	*e;

	e = singleton();
	if (elem->current == 1)
		underline_on();
	if (elem->selected == 1)
		reverse_video();
	ft_putstr_fd(elem->content, e->tty_out);
	if (elem->current == 1)
		underline_off();
	if (elem->selected == 1)
		cancel_mode();
}
