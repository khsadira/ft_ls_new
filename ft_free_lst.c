/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:53:21 by khsadira          #+#    #+#             */
/*   Updated: 2018/08/31 11:53:22 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lst_free(t_lst **list)
{
	t_lst	*tmp;

	while (*list)
	{
		tmp = *list;
		if (tmp->name)
			ft_strdel(&tmp->name);
		if (tmp->path)
			ft_strdel(&tmp->path);
		*list = (*list)->next;
		free(tmp);
	}
}
