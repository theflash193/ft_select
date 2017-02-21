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
	struct termios p;

	if (ac == 1)
		return (0);
	ft_bzero(&e, sizeof(e));
	if ((e.term_type = getenv("TERM")) == NULL)
		return (-1);
	if ((tgetent(NULL, e.term_type)) == -1)
		return (-1);
	e.termios = (struct termios *)malloc(sizeof(struct termios));
	if (tcgetattr(0, &p) == -1)
	{
		putendl_fd("fail to get termios", 1);
		return (-1);
	}
	if ((e.default_termios = (struct termios *)malloc(sizeof(struct termios))) == NULL)
		return (-1);
	ft_memcpy(e.default_termios, &p, sizeof(struct termios));
	p.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	p.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	p.c_cc[VMIN] = 1;
	p.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &p) == -1)
		return (-1);
	ft_memcpy(e.termios, &p, sizeof(struct termios));
	// if (set_terminal(&e) == -1)
	// 	return (0);
	parser(&e, ac, av);
	if (get_terminal_dimension(&e) == -1)
		reset_terminal(&e);
	loop(&e);
	//	reset_terminal(&e);
	return (0);
}
