/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 05:52:21 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 06:36:47 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	parser(t_env *e, int ac, char **av)
{
	t_select	data;
	t_clst		*elem;
	int			i;

	i = 1;
	while (i < ac)
	{
		data.content = ft_strdup(av[i++]);
		elem = clst_new(&data, sizeof(t_select));
		clst_push_back(&(e->liste_selection), elem);
	}
}
