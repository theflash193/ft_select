/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_terminal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:00:22 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:01:00 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	configuration_terminal(t_env *e)
{
	refresh_window();
	if (invisible_cursor() == -1)
		return (-1);
	return (0);
}
