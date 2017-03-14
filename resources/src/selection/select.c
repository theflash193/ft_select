/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:16:36 by grass-kw          #+#    #+#             */
/*   Updated: 2017/02/28 23:29:59 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	e->max_len = 0;
	clst_iter(e->liste_selection, calcul_max);
}

void		ft_spaces_characteristics(int nb, int fd)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
}

int		configuration_padding_selection(t_env *e)
{
	t_padding	p;

	p.nombre_colonne = 1;
  	p.nombre_colonne += e->nombre_argument / e->line;
	p.taille_colonne = p.nombre_colonne * (e->max_len + 2);
      	//printf("[nb col %d] [elem pc%d] [argument %d]\n", p.nombre_colonne, p.element_par_colonne, e->argument_par_ligne);
	if (p.taille_colonne > e->colonne)
		return (0);
	e->padding = p;
	return (1);
}

void	affichage_selection(t_env *e)
{
	update_maxlen();
	if ((configuration_padding_selection(e)) == 0)
		message_taille_insufissante(e);
	else
		affichage_padding(e->liste_selection, print_data, e);
}

void	message_taille_insufissante(t_env *e)
{
	int		taille_message;

	taille_message = ft_strlen("taille ecran insufisant");
	if (taille_message <= e->colonne)
		ft_putstr_fd("taille ecran insufisant", e->tty_out);
}

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
	int	j;

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
