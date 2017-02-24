#include "ft_select.h"

t_env 	*singleton(void)
{
	static t_env *e = NULL;

	if (e == NULL)
	{
		e = (t_env *)malloc(sizeof(t_env));
		ft_bzero(e, sizeof(t_env));
	}
	return (e);
}

void	free_singleton(void)
{
	t_env *e;

	e = singleton();
	if (e->liste_selection != NULL)
		clst_del(&(e->liste_selection), delete_selection);
	ft_bzero(e, sizeof(t_env));
	ft_memdel((void *)&e);
}
