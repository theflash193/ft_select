#include "ft_select.h"

void	event_select(t_env *e)
{
	t_select	*current;

	current = e->current_elem->content;
	if (current->selected == 0)
		selected(e);
	else
		disable_seleted(e);
}
