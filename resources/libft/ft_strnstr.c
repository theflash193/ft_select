/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 14:29:43 by grass-kw          #+#    #+#             */
/*   Updated: 2015/02/10 10:54:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (s1[i + j] != '\0' && s1[i + j] == s2[j] && i + j < n)
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		j = 0;
		i++;
	}
	return (NULL);
}
