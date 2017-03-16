#include "ft_select.h"

void	calcul_max(t_clst *elem)
{
	t_select *item;
	t_env *e;

	e = singleton();
	item = (t_select*)elem->content;
	e->max_len = (e->max_len < item->len) ? item->len : e->max_len;
}
