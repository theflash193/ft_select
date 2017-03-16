#include "ft_select.h"

void   	positionnement_cursor(t_env *e, int index, int colonne_courante)
{
	e->padding.position_ligne_cursor = index % e->line;
	e->padding.position_colonne_cursor = (colonne_courante) * (e->max_len + 2);
	move_cursor(e->padding.position_ligne_cursor, e->padding.position_colonne_cursor);
}
