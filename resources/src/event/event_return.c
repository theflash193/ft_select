#include "ft_select.h"

void	clst_iter_custom(t_clst *alst, void (*f)(t_clst *), int fd)
{
	t_clst		*cursor;
	t_select	*elem;
	int		retour_chariot;

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
	clear_window();
	normal_cursor();
	clst_iter_custom(e->liste_selection, affichage_terminal, 1);
	if (tcsetattr(0, 0, e->default_termios) == -1)
		putendl_fd("fail to connect termios", 1);
	clear_env(e);
}
