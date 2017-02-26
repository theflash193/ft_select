#include "ft_select.h"

int	cp_string(char *id)
{
	t_env	*e;
	char	*str;

	e = singleton();
	if ((str = tgetstr(id, NULL)) == NULL)
		return (-1);
	else
	  ft_putstr_fd(str, e->tty_out);
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

void	cancel_mode()
{
	cp_string("me");
}

void	reverse_video()
{
	cp_string("mr");
}

void	clear_window()
{
	t_env	*e;
	unsigned short i;

	i = 0;
	e = singleton();
	refresh_window();
	while (i++ < e->line)
		cp_string("dl");
}
