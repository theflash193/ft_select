/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 07:19:37 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 07:20:17 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	loop(t_env *e)
{
	char	buff[4];

	while (42)
	{
		clear_window();//clear_window
		affichage_selection(e);//affichage de la liste
		//attente lecture utilisateur
		ft_bzero(&buff, 4);
		read(0, &buff, 3);
		if (event_gesture(e, buff) == -1)
			break ;
	//gestion evenement touche utilisateur
	}
}
