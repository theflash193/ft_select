/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:53:04 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/17 15:47:05 by grass-kw         ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>

# define SELECT(a) *(t_select *)(a)

typedef struct			s_padding
{
	int					nombre_colonne;
	int					taille_colonne;
	int					position_ligne_cursor;
	int					position_colonne_cursor;
}						t_padding;

typedef struct			s_env
{
	t_clst				*liste_selection;
	t_clst				*current_elem;
	struct termios		*termios;
	struct termios		*default_termios;
	char				*term_type;
	struct winsize		win_size;
	int					line;
	int					colonne;
	int					tty_in;
	int					tty_out;
	size_t				max_len;
	int					nombre_argument;
	int					argument_par_ligne;
	t_padding			padding;
}						t_env;

typedef struct			s_select
{
	char				*content;
	int					current;
	int					selected;
	size_t				len;
}						t_select;

/*
** parser
*/
void					parser(t_env *e, int ac, char **av);
void					delete_selection(void *content, size_t content_size);
void					clear_env(t_env *e);

/*
** coreutils
*/
void					print_data(t_clst *alst);
void					print_select(t_env *e);
t_env					*singleton(void);
void					free_singleton(void);
void					clst_del_elem(t_clst **alst, void (*del)(void *,
	size_t));
void					putstr_fd(const char *s, int fd);
int						putchar_fd(char c, int fd);
int						putendl_fd(char const *s, int fd);
int						sputchar(int c);

/*
** terminal
*/
int						configure_select_termios(t_env *e);
void					reset_terminal(void);
int						get_terminal_dimension(t_env *e);
int						configuration_terminal(t_env *e);
int						get_tty_name(t_env *e);
int						get_terminal_dimension(t_env *e);

/*
** capacity
*/
int						cp_string(char *id);
int						underline_on(void);
int						underline_off(void);
void					clear_window(void);
int						invisible_cursor(void);
int						normal_cursor(void);
void					refresh_window(void);
void					reverse_video(void);
void					cancel_mode(void);
void					move_cursor(int x, int y);

/*
** selection
*/
void					loop(t_env *e);
void					affichage_element(t_select *elem);
void					affichage_selection(t_env *e);
void					calcul_max(t_clst *elem);
void					update_maxlen(void);
void					cursor_next(t_env *e);
void					cursor_prev(t_env *e);
int						set_terminal(t_env *e);
void					affichage_padding(t_clst *alst, void (*f)(t_clst *),
	t_env *e);
void					message_taille_insufissante(t_env *e);
int						configuration_padding_selection(t_env *e);

/*
** event_gesture
*/
int						event_gesture(t_env *e, char *s);
void					event_quit(t_env *e);
void					event_up(t_env *e);
void					event_down(t_env *e);
void					event_select(t_env *e);
void					event_return(t_env *e);
void					event_select(t_env *e);
void					event_delete(t_env *e);

/*
** signal
*/
void					changement_taille_fenetre(int i);
void					pause_programme(int i);
void					reprise_programme(int i);
void					signal_handler(void);

#endif
