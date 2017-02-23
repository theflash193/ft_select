#include "ft_select.h"

void	affichage_element(t_select *elem)
{

	if (elem->current == 1)
		underline_on();
	if (elem->selected == 1)
		reverse_video();
	putstr_fd(elem->content, 1);
	if (elem->current == 1)
		underline_off();
	if (elem->selected == 1)
		cancel_mode();
	putchar_fd(' ', 1);
}

void	affichage_selection(t_env *e)
{
	clst_iter(e->liste_selection, print_data);
	putendl_fd("", 1);
}