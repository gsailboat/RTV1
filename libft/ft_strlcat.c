/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:40:14 by gselbo            #+#    #+#             */
/*   Updated: 2016/12/02 17:41:33 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i] && i < n)
		i++;
	j = i;
	while ((i + 1) < n)
	{
		s1[i] = s2[i - j];
		i++;
	}
	if (j < n)
		s1[i] = '\0';
	return (j + ft_strlen(s2));
}