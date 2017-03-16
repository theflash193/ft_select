#include "ft_select.h"

void	changement_taille_fenetre(int i)
{
	t_env *e;

	e = singleton();
	get_terminal_dimension(e);
	clear_window();
	update_maxlen();
	affichage_selection(e);
}

