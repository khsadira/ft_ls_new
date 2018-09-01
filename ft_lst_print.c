/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:15:40 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/01 20:45:31 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_phys(t_lst *list)
{
	while (list)
	{
		if (S_ISCHR(list->buf.st_mode) || S_ISBLK(list->buf.st_mode))
			return (1);
		list = list->next;
	}
	return (0);
}

static void	ft_lstprint_r(t_lst *list, t_flag *flag,
				t_size *size_l, long long int blocks)
{
	int		phys;
	t_size	*size;

	size = ft_format_spec(flag, size, list);
	phys = ft_phys(list);
	while (list && list->next)
		list = list->next;
	while (list)
	{
		ft_print_flag(flag, size, list);
		if (flag && flag->l == 1)
		{
			ft_lstprint_l(list, size_l, phys);
			if (S_ISLNK(list->buf.st_mode))
				ft_print_ln(list);
			else
				ft_putendl(list->name);
		}
		else
			ft_putendl(list->name);
		list = list->bfr;
	}
	free(size);
}

static void	ft_lstprint_norm(t_lst *list, t_flag *flag,
					t_size *size_l, long long int blocks)
{
	int		phys;
	t_size	*size;

	size = ft_format_spec(flag, size, list);
	phys = ft_phys(list);
	while (list)
	{
		ft_print_flag(flag, size, list);
		if (flag && flag->l == 1)
		{
			ft_lstprint_l(list, size_l, phys);
			if (S_ISLNK(list->buf.st_mode))
				ft_print_ln(list);
			else
				ft_putendl(list->name);
		}
		else
			ft_putendl(list->name);
		list = list->next;
	}
	free(size);
}

void		ft_lstprint(t_lst *list, t_flag *flag,
			t_size *size_l, long long int blocks)
{
	int	i;
	int	phys;

	phys = ft_phys(list);
	i = 0;
	if (flag && flag->l == 1 && blocks != -1 && list)
	{
		ft_putstr("total ");
		ft_put_off_t(blocks);
		ft_putendl("");
	}
	if (flag && flag->r == 1)
		ft_lstprint_r(list, flag, size_l, blocks);
	else
		ft_lstprint_norm(list, flag, size_l, blocks);
}
