#include "ft_select.h"

void	reset_terminal(void)
{
	t_env *e;

	e = singleton();
	clear_window();
	normal_cursor();
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", 1);
	free_singleton();
}

