#include "ft_select.h"

int		get_terminal_dimension(t_env *e)
{
	struct winsize win_size;

	if (ioctl(0, TIOCGSIZE, &win_size) == -1)
		return (-1);
	e->line = win_size.ws_row;
	e->colonne = win_size.ws_col;
	return (0);
}
