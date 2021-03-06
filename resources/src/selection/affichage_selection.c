/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:09:49 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:09:54 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			configuration_padding_selection(t_env *e)
{
	t_padding	p;

	p.nombre_colonne = 1;
	p.nombre_colonne += e->nombre_argument / e->line;
	p.taille_colonne = p.nombre_colonne * (e->max_len + 2);
	if (p.taille_colonne > e->colonne)
		return (0);
	e->padding = p;
	return (1);
}

void		affichage_selection(t_env *e)
{
	update_maxlen();
	if ((configuration_padding_selection(e)) == 0)
		message_taille_insufissante(e);
	else
		affichage_padding(e->liste_selection, print_data, e);
}
