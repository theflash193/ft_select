#include "ft_select.h"

void	message_taille_insufissante(t_env *e)
{
	int		taille_message;

	taille_message = ft_strlen("taille ecran insufisant");
	if (taille_message <= e->colonne)
		ft_putstr_fd("taille ecran insufisant", e->tty_out);
}
