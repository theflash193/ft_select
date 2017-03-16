#include "ft_select.h"

int 	configuration_terminal(t_env *e)
{
	refresh_window();
	if (invisible_cursor() == -1)
		return (-1);
	return (0);
}
