/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_maxlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:02:08 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:02:08 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			update_maxlen(void)
{
	t_env *e;

	e = singleton();
	e->max_len = 0;
	clst_iter(e->liste_selection, calcul_max);
}
