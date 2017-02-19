#include "ft_select.h"

int	cp_string(char *id)
{
    char *str;

    if ((str = tgetstr(id, NULL)) == NULL)
      return (-1);
    else
    	tputs(str, 1, putchar);
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


void	clear_window(void)
{
	cp_string("cl");
	tputs(tgoto("cm", 0, 0), 0, putchar);
}
