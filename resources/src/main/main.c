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
/*
void	clear_window(void)
{
	cp_string("cl");
	tputs(tgoto("cm", 0, 0), 0, ft_putchar);
}

void	configuration_terminal(t_env *e)
{
    	if ((str = tgetstr("cl", NULL)) == NULL)
  		s_putendl_fd("fail to get capability");
    	else
    		tputs(str, 1, ft_putchar);
    	clear_window();
    	cp_string("vi");
}

int	cp_string(char *id)
{
    char *str;

    if ((str = tgetstr(id, NULL)) == NULL)
      return (-1);
    else
    	tputs(str, 1, putchar);
    return (0);
}
*/
int 	configure_select_termios(t_env *e)
{
	e->termios = (struct termios *)malloc(sizeof(struct termios));
	if (tcgetattr(0, e->termios) == -1)
	{
	  putendl_fd("fail to get termios", 1);
		return (-1);
	}
	if ((e->default_termios = (struct termios *)malloc(sizeof(struct termios))) == NULL)
	  return (-1);
	ft_memcpy(e->default_termios, e->termios, sizeof(struct termios));
	e->termios->c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	e->termios->c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	e->termios->c_cc[VMIN] = 1;
	e->termios->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, e->termios) == -1)
		return (-1);
	return (0);
}

int	set_terminal(t_env *e)
{
	int success;
	int i;
	unsigned long u;

	e->term_type = getenv("TERM");
	if (e->term_type == 0)
	{
	  putendl_fd("tertype not found", 1);
		return (-1);
	}
	success = tgetent(0, e->term_type);
	if (success == 0)
	{
		putendl_fd("Could not access the termcap data base.", 1);
		return (-1);
	}
	if (success == 0)
	{
		putendl_fd("Terminal type `%s' is not defined.\n\n", 1);
		return (-1);
	}
	if (configure_select_termios(e) == -1)
	  return (-1);
}

void	reset_terminal(t_env *e)
{
  //cp_string("cl");
  //cp_string("ve");

	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", 1);
	clear_env(e);
}

int main(int ac, char **av)
{
	t_env	e;
	char	buff[4];

	if (ac == 1)
		return (0);
	ft_bzero(&e, sizeof(e));
	parser(&e, ac, av);
	set_terminal(&e);
	// On applique les changements :
	while (42)
	{
	  print_select(&e);
	  read(0, &buff, 3);
	  buff[3] = '\0';
	  if (buff[0] == 'd')
	    {
	      if (tcsetattr(0, 0, e.default_termios) == -1)
      		putendl_fd("fail to connect termios", 1);
	      reset_terminal(&e);
	      return (0);
	    }
	}
	
// loop(&e);
	//	reset_terminal(&e);

	return (0);
}

