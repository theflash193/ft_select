/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:17:33 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/14 19:19:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*singleton(void)
{
	static t_env *e = NULL;

	if (e == NULL)
	{
		e = (t_env *)malloc(sizeof(t_env));
		ft_bzero(e, sizeof(t_env));
	}
	return (e);
}

void	free_singleton(void)
{
	t_env *e;

	e = singleton();
	if (e->liste_selection != NULL)
		clst_del(&(e->liste_selection), delete_selection);
	ft_bzero(e, sizeof(t_env));
	ft_memdel((void *)&e);
}
