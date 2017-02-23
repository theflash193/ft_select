#include "ft_select.h"

void	event_quit(t_env *e)
{
	reset_terminal(e);
}

void	event_left(t_env *e)
{
	cursor_prev(e);
}

void	event_right(t_env *e)
{
	cursor_next(e);
}

t_select	*find_next(t_clst *alst)
{
	t_clst 		*cursor;
	t_select	*elem;

	cursor = alst;
	if (cursor == NULL)
		return (NULL);
	elem = (t_select *)cursor->content;
	while (cursor->next != alst && cursor != NULL)
	{
		cursor = cursor->next;
		if (elem->current == 0)
			return (elem);
	}
	return (NULL);
}

void	event_select(t_env *e)
{
	t_select	*current;
	t_select	*next;

	current = e->current_elem->content;
	current->selected = 1;
	if ((next = find_next(e->current_elem->content)) != NULL)
	{
		next->current = 1;
		current->current = 0;
	}
}

int 	event_gesture(t_env *e, char *s)
{
	if (s[0] == 'd')
	{
		reset_terminal(e);
		return (-1);
	}
	if (s[0] == 'w')
		event_left(e);
	if (s[0] == 's')
		event_right(e);
	if (s[0] == 'p')
		event_select(e);
	return (0);
}