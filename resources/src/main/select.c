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

int		calcul_argument_ligne(t_env *e)
{
	int nombre_ligne_necessaire;

	e->argument_par_ligne = e->colonne / e->max_len + 4;
	nombre_ligne_necessaire = (e->line * e->nombre_argument) / e->argument_par_ligne;
	printf("[e->argument_par_ligne %d] [e->line %hu] [e->nombre_argument %d] [max len %zu]\n", e->argument_par_ligne, e->line, e->nombre_argument, e->max_len);
	if (e->max_len + 4 > e->colonne)
		return (0);
	return ((e->max_len + 4 <= e->colonne) && (nombre_ligne_necessaire <= e->line));
}

void	affichage_selection(t_env *e)
{
	update_maxlen();
	if ((calcul_argument_ligne(e)) == 0)
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

void	affichage_padding(t_clst *alst, void (*f)(t_clst *), t_env *e)
{
	t_clst		*cursor;
	t_select	*elem;
	int			i;

	i = 0;
	cursor = alst;
	if (cursor == NULL)
		return ;
	elem = (t_select *)cursor->content;
	f(cursor);
	while (cursor->next != alst && cursor != NULL)
	{
		if (i == e->argument_par_ligne)
			i = 0;
		if (i != 0 || i != e->argument_par_ligne)
			ft_putchar_fd(' ', e->tty_out);
		cursor = cursor->next;
		elem = (t_select *)cursor->content;
		f(cursor);
		if (i == e->argument_par_ligne)
			ft_putchar_fd('\n', e->tty_out);
		i++;
	}
	ft_putchar_fd('\n', e->tty_out);
}
