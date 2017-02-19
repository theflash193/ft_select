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
	  	  read(0, &buff, 3);
	  buff[3] = '\0';
	  if (buff[0] == 'd')
	  {
	      if (tcsetattr(0, 0, e->default_termios) == -1)
      		putendl_fd("fail to connect termios", 1);
	      reset_terminal(e);
	      break ;
	  }
	  //gestion evenement touche utilisateur
	}
}
