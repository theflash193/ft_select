/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 22:31:40 by grass-kw          #+#    #+#             */
/*   Updated: 2017/02/28 23:18:57 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signal_handler(void)
{
	signal(SIGWINCH, changement_taille_fenetre);
	signal(SIGTSTP, pause_programme);
	signal(SIGCONT, reprise_programme);
}
