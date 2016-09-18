/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 07:20:40 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int main(int ac, char **av)
{
	t_env	e;

	if (ac == 1)
		return (0);
	ft_bzero(&e, sizeof(e));
	parser(&e, ac, av);
	print_select(&e);
	// loop(&e);
	clear_env(&e);
	return (0);
}
