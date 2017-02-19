/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 09:54:05 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	putstr_fd(const char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (0);
}


int	putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (0);
}

void	sputchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	t_env	e;


	if (ac == 1)
		return (0);
	ft_bzero(&e, sizeof(e));
	parser(&e, ac, av);
	set_terminal(&e);
	loop(&e);
	//	reset_terminal(&e);

	return (0);
}

