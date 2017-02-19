#include "ft_select.h"

void	affichage_element(t_select *elem)
{
	putstr_fd(elem->content, 1);
	putchar_fd(' ', 1);
}

void	affichage_selection(t_env *e)
{
	clst_iter(e->liste_selection, print_data);
	putendl_fd("", 1);
}
