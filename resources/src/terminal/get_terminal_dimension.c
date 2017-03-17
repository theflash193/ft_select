/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminal_dimension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:57:49 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 15:59:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_terminal_dimension(t_env *e)
{
	struct winsize	win_size;

	if (ioctl(0, TIOCGSIZE, &win_size) == -1)
		return (-1);
	e->line = win_size.ws_row;
	e->colonne = win_size.ws_col;
	return (0);
}
