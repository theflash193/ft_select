#include "ft_select.h"

void	affichage_element(t_select *elem)
{
	t_env	*e;

	e = singleton();
	if (elem->current == 1)
		underline_on();
	if (elem->selected == 1)
		reverse_video();
	ft_putstr_fd(elem->content, e->tty_out);
	if (elem->current == 1)
		underline_off();
	if (elem->selected == 1)
		cancel_mode();
}
