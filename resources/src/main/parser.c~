/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 05:52:21 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 07:06:23 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	init_select(char *content, t_select *elem)
{
	ft_bzero(elem, sizeof(t_select));
	elem->content = ft_strdup(content);
}

static void setup_select(int i, t_select *elem)
{
	if (i == 1)
		elem->current = 1;
}

void	parser(t_env *e, int ac, char **av)
{
	t_select	data;
	t_clst		*elem;
	int			i;

	i = 1;
	while (i < ac)
	{
		init_select(av[i], &data);
		setup_select(i++, &data);
		elem = clst_new(&data, sizeof(t_select));
		clst_push_back(&(e->liste_selection), elem);
	}
	e->current_elem = e->liste_selection;
}
