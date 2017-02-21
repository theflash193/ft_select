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

void	clear_window(t_env *e)
{
	unsigned short i;

	i = 0;
	tputs(tgoto("cm", 0, 0), 0, putchar);
	while (i++ < e->line)
		cp_string("dl");
}
