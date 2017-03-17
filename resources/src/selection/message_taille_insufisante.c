/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_taille_insufisante.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:04:00 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:04:01 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	message_taille_insufissante(t_env *e)
{
	int		taille_message;

	taille_message = ft_strlen("taille ecran insufisant");
	if (taille_message <= e->colonne)
		ft_putstr_fd("taille ecran insufisant", e->tty_out);
}
