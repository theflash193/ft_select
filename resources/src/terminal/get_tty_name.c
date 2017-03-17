/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tty_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:56:51 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 15:57:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_tty_name(t_env *e)
{
	char	*tty_out_name;
	int		fd;

	tty_out_name = NULL;
	if ((tty_out_name = ttyname(0)) == NULL)
	{
		reset_terminal();
		ft_putendl_fd("ttyname fail", 2);
		exit(0);
	}
	if ((e->tty_out = open(tty_out_name, O_WRONLY)) < -1)
	{
		reset_terminal();
		ft_putendl_fd("open fail", 2);
		exit(0);
	}
	return (0);
}
