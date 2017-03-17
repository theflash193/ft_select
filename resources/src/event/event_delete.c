#include "ft_select.h"

void	event_delete(t_env *e)
{
	t_clst		*delete;
	t_select	*tmp;

	if (e->current_elem == e->liste_selection)
		e->liste_selection = e->liste_selection->next;
	delete = e->current_elem;
  	e->current_elem = delete->next;
	tmp = (t_select *)delete->next->content;
	tmp->current = 1;
	clst_del_elem(&delete, delete_selection);
	e->nombre_argument--;
}
