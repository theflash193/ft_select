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

void	set_terminal(t_env *e)
{
	struct termios p;
	char term_buffer[2048];
	char *term_type = getenv("TERM");
	int success;

	if (term_type == 0)
	{
		ft_putendl("tertype not found");
		exit(0);
	}
	success = tgetent(0, term_type);
	if (success == 0)
	{
		printf("%s\n", "Could not access the termcap data base.");
		exit(0);
	}
	if (success == 0)
	{
		printf("Terminal type `%s' is not defined.\n\n", term_type);
		exit(0);
	}
	printf("term : %s\n", term_buffer);
	int fildes;
	int i;
	unsigned long u;
	fildes = ioctl(i, u);
	tcgetattr(fildes, &p);
	p.c_lflag &= ~(ICANON); // Met le pinal en mode canonique.
	p.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le pinal
	p.c_cc[VMIN] = 1;
	p.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &p) == -1)
		exit(0);
}

int main(int ac, char **av)
{
	t_env	e;

	if (ac == 1)
		return (0);
	ft_bzero(&e, sizeof(e));
	parser(&e, ac, av);
	print_select(&e);
	set_terminal(&e);
	// loop(&e);
	clear_env(&e);
	return (0);
}
