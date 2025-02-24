/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 20:41:21 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/04 10:00:30 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lnk(t_lst *list)
{
	char	link[255];
	int		rl;

	rl = 0;
	if ((rl = readlink(list->path, link, 255)))
	{
		link[rl] = '\0';
		ft_putendl(link);
	}
}

void		ft_print_ln(t_lst *list, int flag)
{
	ft_print_f(list, flag, 0);
	ft_putstr(" -> ");
	ft_lnk(list);
}
