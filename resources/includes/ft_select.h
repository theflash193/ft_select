/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:53:04 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 06:09:28 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include "clst.h"
# include <stdio.h>
#include <stdlib.h>

typedef struct	s_env
{
	t_clst		*liste_selection;
}				t_env;

void			parser(t_env *e, int ac, char **av);
void			delete_selection(void *content, size_t content_size);
void			clear_env(t_env *e);

#endif
