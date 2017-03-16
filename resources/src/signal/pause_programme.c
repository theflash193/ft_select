#include "ft_select.h"

void	pause_programme(int i)
{
	t_env *e;
	char cp[1];


	e = singleton();
	cp[0] =  e->default_termios->c_cc[VSUSP];
	clear_window();
	normal_cursor();
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", e->tty_out);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}
