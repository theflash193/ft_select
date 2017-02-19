#include "ft_select.h"


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
	return(0);
}

void	reset_terminal(t_env *e)
{
  //cp_string("cl");
  //cp_string("ve");

	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", 1);
	clear_env(e);
}
