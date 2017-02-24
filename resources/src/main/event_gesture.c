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

t_clst	*find_next(t_clst *alst)
{
	t_clst 		*cursor;
	t_select	*elem;

	cursor = alst;
	if (cursor == NULL)
		return (NULL);
	cursor = cursor->next;
	elem = (t_select *)cursor->content;
	while (cursor->next != alst && cursor != NULL)
	{
		elem = (t_select *)cursor->content;
		if (elem->current == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

void	selected(t_env *e)
{
	t_select	*current;
	t_select	*tmp;
	t_clst		*next;

	current = e->current_elem->content;
	current->selected = 1;
	if ((next = find_next(e->current_elem)) != NULL)
	{
		tmp = (t_select *)next->content;
		tmp->current = 1;
		current->current = 0;
		e->current_elem = next;
	}
}

void	disable_seleted(t_env *e)
{
	t_select	*current;

	current = e->current_elem->content;
	current->selected = 0;
}

void	event_select(t_env *e)
{
	t_select	*current;

	current = e->current_elem->content;
	if (current->selected == 0)
		selected(e);
	else
		disable_seleted(e);
}

void	clst_iter_custom(t_clst *alst, void (*f)(t_clst *), int fd)
{
	t_clst *cursor;
	t_select	*elem;
	int			retour_chariot;

	retour_chariot = 0;
	cursor = alst;
	if (cursor == NULL)
		return ;
	elem = (t_select *)cursor->content;
	if (elem->selected == 1)
	{
		ft_putstr_fd(elem->content, fd);
		ft_putchar_fd(' ', fd);
		retour_chariot = 1;
	}
	while (cursor->next != alst && cursor != NULL)
	{
		cursor = cursor->next;
		elem = (t_select *)cursor->content;
		if (elem->selected == 1)
		{
			ft_putstr_fd(elem->content, fd);
			ft_putchar_fd(' ', fd);
			retour_chariot = 1;
		}
	}
	if (retour_chariot)
		ft_putchar_fd('\n', 1);
}

void	affichage_terminal(t_clst *cursor)
{
	t_select	*elem;

	elem = (t_select *)cursor->content;
	if (elem->selected == 1)
		ft_putstr(elem->content);
}

void	event_return(t_env *e)
{
	clear_window(e);
	normal_cursor();
	clst_iter_custom(e->liste_selection, affichage_terminal, 1);
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", 1);
	clear_env(e);
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
	if (s[0] == 'l')
	{
		event_return(e);
		return (-1);
	}
	return (0);
}
