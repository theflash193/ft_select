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
	write(fd, s, ft_strlen(s));
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

int	sputchar(int c)
{
	write(1, &c, 1);
	return (0);
}

int main(int ac, char **av)
{
	t_env	*e;

	if (ac == 1)
		return (0);
	e = singleton();
	if (set_terminal(e) == -1 || configuration_terminal(e) || get_tty_name(e) == -1)
	{
		reset_terminal();
		return (0);
	}
	parser(e, ac, av);
	if (get_terminal_dimension(e) == -1)
		reset_terminal();
	loop(e);
	return (0);
	}

 /*int main()
{
	int buff;
	t_env	*e;

		e = singleton(); 
	while (42)
	{
	  read(0, &buff, sizeof(int));
		printf("[%d]\n", buff);
	}
	return (0);
}*/
