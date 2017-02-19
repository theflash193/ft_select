/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:53:04 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 09:40:28 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include "clst.h"
# include <stdio.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
#include <sys/ioctl.h>
# define SELECT(a) *(t_select *)(a)

typedef struct	s_env
{
	t_clst		*liste_selection;
	t_clst		*current_elem;
  	struct termios	*termios;
 	struct termios	*default_termios;
	char		term_buffer[2048];
	char		*term_type;
}				t_env;

typedef struct	s_select
{
	char		*content;
	int			current;
}				t_select;

void			parser(t_env *e, int ac, char **av);
void			delete_selection(void *content, size_t content_size);
void			clear_env(t_env *e);
void			print_data(t_clst *alst);
void			print_select(t_env *e);
void			loop(t_env *e);
void			cursor_next(t_env *e);
void			cursor_prev(t_env *e);

#endif
