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
	int success;
	int i;
	unsigned long u;

	e->term_type = getenv("TERM");
	if (e->term_type == 0)
	{
		ft_putendl("tertype not found");
		exit(0);
	}
	success = tgetent(0, e->term_type);
	if (success == 0)
	{
		printf("%s\n", "Could not access the termcap data base.");
		exit(0);
	}
	if (success == 0)
	{
		printf("Terminal type `%s' is not defined.\n\n", e->term_type);
		exit(0);
	}
	e->fildes = ioctl(i, u);
	char *name_tty;


	tcgetattr(e->fildes, &(e->p));/*
	e->p.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	e->p.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	e->p.c_cc[VMIN] = 1;
	e->p.c_cc[VTIME] = 0;*/
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &(e->p)) == -1)
		exit(0);
}

void	reset_terminal(t_env *e)
{
	int i;
	unsigned long u;
	int fildes;
  	struct termios	p;

  if (tcgetattr(0, &p) == -1)
    ft_putendl("fail to get termios");
  e->p.c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, TCSADRAIN, &p) == -1)
      ft_putendl("fail to connect termios");
}
/*
int main(int ac, char **av)
{
	t_env	e;
	char	buff[4];

	if (ac == 1)
		return (0);
	ft_bzero(&e, sizeof(e));
	parser(&e, ac, av);
	print_select(&e);
	set_terminal(&e);
	while (42)
	  {
	    read(0, &buff, 3);
	    buff[3] = '\0';
	    if (buff[0] == 'd')
	    {
	      reset_terminal(&e);
	      return (0);
	    }
	    }
	// loop(&e);
	clear_env(&e);
	return (0);
}*/

int main(int ac, char **av)
{
  char *tty_name;
  
	if (ac == 1)
    		return (-1);
	if ((tty_name = ttyname(ft_atoi(av[1]))) == NULL)
		ft_putendl("fail to get ttyname");
	else
		ft_putendl(tty_name);
    return (0);
}
int main(int ac, char **av)
{
  
	if (ac == 1)
    		return (-1);
	if ((tty_name = ttyname(ft_atoi(av[1]))) == NULL)
		ft_putendl("fail to get ttyname");
	else
		ft_putendl(tty_name);
    return (0);
}
