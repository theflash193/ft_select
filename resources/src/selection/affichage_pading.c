#include "ft_select.h"

void   	positionnement_cursor(t_env *e, int index, int colonne_courante)
{
	e->padding.position_ligne_cursor = index % e->line;
	e->padding.position_colonne_cursor = (colonne_courante) * (e->max_len + 2);
	move_cursor(e->padding.position_ligne_cursor, e->padding.position_colonne_cursor);
}

void	affichage_padding(t_clst *alst, void (*f)(t_clst *), t_env *e)
{
	t_clst		*cursor;
	t_select	*elem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cursor = alst;
	if (cursor == NULL)
		return ;
	positionnement_cursor(e, i, j);
	elem = (t_select *)cursor->content;
	f(cursor);
	i++;
	while (cursor->next != alst && cursor != NULL)
	{
		if (i % e->line == 0)
			j++;
		cursor = cursor->next;
	       	positionnement_cursor(e, i, j);
		elem = (t_select *)cursor->content;
		f(cursor);
		i++;
	}
}
