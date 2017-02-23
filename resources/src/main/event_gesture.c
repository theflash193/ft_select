#include "ft_select.h"

void	event_quit(t_env *e)
{
	reset_terminal(e);
}

void	event_left(t_env *e)
{
  	cursor_prev(e);
}

void	event_right(t_env *e)
{
	cursor_next(e);
}

int 	event_gesture(t_env *e, char *s)
{
	if (s[0] == 'd')
	{
		reset_terminal(e);
		return (-1);
	}
	if (s[0] == 'w')
		event_left(e);
	if (s[0] == 's')
		event_right(e);
	return (0);
}
