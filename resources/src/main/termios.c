#include "ft_select.h"

int 	configure_select_termios(t_env *e)
{
	// e->termios = (struct termios *)malloc(sizeof(struct termios));
	// if (tcgetattr(0, e->termios) == -1)
	// {
	//   putendl_fd("fail to get termios", 1);
	// 	return (-1);
	// }
	// if ((e->default_termios = (struct termios *)malloc(sizeof(struct termios))) == NULL)
	//   return (-1);
	// ft_memcpy(e->default_termios, e->termios, sizeof(struct termios));
	// e->termios->c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	// e->termios->c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	// e->termios->c_cc[VMIN] = 1;
	// e->termios->c_cc[VTIME] = 0;
	// if (tcsetattr(0, TCSADRAIN, e->termios) == -1)
	// 	return (-1);
	return (0);
}

int	set_terminal(t_env *e)
{
	struct termios p;

	if ((e->term_type = getenv("TERM")) == NULL)
		return (-1);
	if ((e->term_type = getenv("TERM")) == NULL)
		return (-1);
	if ((tgetent(NULL, e->term_type)) == 0)
		return (-1);
	e->termios = (struct termios *)malloc(sizeof(struct termios));

	if (tcgetattr(0, &p) == -1)
	{
		putendl_fd("fail to get termios", 1);
		return (-1);
	}
	if ((e->default_termios = (struct termios *)malloc(sizeof(struct termios))) == NULL)
		return (-1);
	ft_memcpy(e->default_termios, &p, sizeof(struct termios));
	p.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	p.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	p.c_cc[VMIN] = 1;
	p.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &p) == -1)
		return (-1);
	ft_memcpy(e->termios, &p, sizeof(struct termios));
	return(0);
}

void	reset_terminal(t_env *e)
{
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", 1);
	clear_env(e);
}

int	get_terminal_dimension(t_env *e)
{
	struct winsize win_size;

	if (ioctl(0, TIOCGSIZE, &win_size) == -1)
		return (-1);
	e->line = win_size.ws_row;
	e->colonne = win_size.ws_col;
	return (0);
}
