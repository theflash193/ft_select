/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changement_taille_fenetre.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:02:50 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:02:50 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	changement_taille_fenetre(int i)
{
	t_env *e;

	e = singleton();
	get_terminal_dimension(e);
	clear_window();
	update_maxlen();
	affichage_selection(e);
}
