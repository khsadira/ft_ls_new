/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:37:01 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:37:02 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	while (s1[i])
		++i;
	j = 0;
	while (s2[j] && j < n)
	{
		s1[i + j] = s2[j];
		++j;
	}
	s1[i + j] = '\0';
	return (s1);
}
