#include "ft_select.h"

int	cp_string(char *id)
{
	char *str;

	if ((str = tgetstr(id, NULL)) == NULL)
		return (-1);
	else
		putstr_fd(str, 1);
	return (0);
}

int	underline_on(void)
{
	return (cp_string("us"));
}

int	underline_off()
{
	return (cp_string("ue"));
}


int		invisible_cursor(void)
{
	return (cp_string("vi"));
}

int		normal_cursor(void)
{
	return (cp_string("ve"));
}

void	refresh_window()
{
	cp_string("cl");
}
void	clear_window(t_env *e)
{
	unsigned short i;

	i = 0;
	refresh_window();
	while (i++ < e->line)
		cp_string("al");
}
