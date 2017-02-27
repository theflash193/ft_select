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
	putchar_fd(' ', e->tty_out);
}

void	affichage_selection(t_env *e)
{
	clst_iter(e->liste_selection, print_data);
	putendl_fd("", e->tty_out);
}

void	calcul_max(t_clst *elem)
{
  t_select *item;
  t_env *e;

  e = singleton();
  item = (t_select*)elem->content;
  e->max_len = (e->max_len < item->len) ? item->len : e->max_len;
}

void			update_maxlen(void)
{
	t_env *e;

	e = singleton();
	clst_iter(e->liste_selection, calcul_max);
}
