/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:07:37 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:26:47 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor(int x, int y)
{
	char	*str;
	t_env	*e;

	e = singleton();
	str = tgetstr("cm", NULL);
	ft_putstr_fd(tgoto(str, y, x), e->tty_out);
}
