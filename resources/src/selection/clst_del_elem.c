#include "ft_select.h"

void	clst_del_elem(t_clst **alst, void (*del)(void *, size_t))
{
	t_clst	*cursor;
	t_clst	*delete;
	t_clst	*last;
	t_clst	*next;

	if (*alst == NULL)
		return ;
	cursor = *alst;
	delete = cursor;
	if (cursor->next == cursor)
	{
		cursor->next = NULL;
		cursor->prev = NULL;
	}
	else
	{
		next = cursor->next;
		last = cursor->prev;
		last->next = next;
		next->prev = last;
	}
	clst_delone(&delete, (*del));
}
