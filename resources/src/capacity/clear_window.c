/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:08:18 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 16:28:11 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	clear_window(void)
{
	t_env			*e;
	unsigned short	i;

	i = 0;
	e = singleton();
	refresh_window();
}
