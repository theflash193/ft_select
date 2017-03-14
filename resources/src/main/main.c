/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/14 19:18:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int ac, char **av)
{
	t_env	*e;

	if (ac == 1)
		return (0);
	e = singleton();
	if (set_terminal(e) == -1 || configuration_terminal(e) ||
		get_tty_name(e) == -1)
	{
		reset_terminal();
		return (0);
	}
	parser(e, ac, av);
	if (get_terminal_dimension(e) == -1)
		reset_terminal();
	signal_handler();
	loop(e);
	return (0);
}
