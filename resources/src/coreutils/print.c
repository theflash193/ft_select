/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:17:10 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/14 19:17:18 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int		putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (0);
}

int		putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (0);
}

int		sputchar(int c)
{
	write(1, &c, 1);
	return (0);
}
