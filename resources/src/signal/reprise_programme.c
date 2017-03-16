#include "ft_select.h"

void	reprise_programme(int i)
{
	t_env *e;

	e = singleton();
	set_terminal(e);
	configuration_terminal(e);
	update_maxlen();
	affichage_selection(e);
	signal(SIGTSTP, pause_programme);
}
