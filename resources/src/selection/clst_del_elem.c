/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_del_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:04:43 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:04:43 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	clst_del_elem(t_clst **alst, void (*del)(void *, size_t))
{
	t_clst	*cursor;
	t_clst	*delete;
	t_clst	*last;
	t_clst	*next;

	if (*alst == NULL)
		return ;
	cursor = *alst;
	delete = cursor;
	if (cursor->next == cursor)
	{
		cursor->next = NULL;
		cursor->prev = NULL;
	}
	else
	{
		next = cursor->next;
		last = cursor->prev;
		last->next = next;
		next->prev = last;
	}
	clst_delone(&delete, (*del));
}
