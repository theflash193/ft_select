/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprise_programme.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:01:44 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:01:45 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	reprise_programme(int i)
{
	t_env *e;

	e = singleton();
	set_terminal(e);
	configuration_terminal(e);
	update_maxlen();
	affichage_selection(e);
	signal(SIGTSTP, pause_programme);
}
