#include "ft_select.h"

void			update_maxlen(void)
{
	t_env *e;

	e = singleton();
	e->max_len = 0;
	clst_iter(e->liste_selection, calcul_max);
}
