/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:44:10 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:27:45 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	cp_string(char *id)
{
	t_env	*e;
	char	*str;

	e = singleton();
	if ((str = tgetstr(id, NULL)) == NULL)
		return (-1);
	else
		ft_putstr_fd(str, e->tty_out);
	return (0);
}
