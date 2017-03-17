/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:27 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:08:36 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	calcul_max(t_clst *elem)
{
	t_select	*item;
	t_env		*e;

	e = singleton();
	item = (t_select*)elem->content;
	e->max_len = (e->max_len < item->len) ? item->len : e->max_len;
}
