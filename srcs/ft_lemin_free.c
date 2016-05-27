/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 20:02:45 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 14:20:13 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	fRoadsLast(t_data *d)
{
	t_roads		*del;

	del = d->roads;
	if (del->score == 0)
	{
		ft_memdel((void **)&del->tab);
		d->roads = (del->n) ? del->n : NULL;
		ft_strdel(&del->u);
		ft_memdel((void **)&del);
		d->nbroads--;
	}
}

void	fDataLink(t_pBoxLink *lst)
{
	t_pBoxLink	*del;

	while (lst)
	{
		del = lst;
		lst = lst->n;
		ft_memdel((void **)&del);
	}
}

void	fDataRoads(t_data *d)
{
	t_roads		*lst;
	t_roads		*del;

	if (d && d->roads)
	{
		lst = d->roads;
		while (lst)
		{
			del = lst;
			lst = lst->n;
			ft_memdel((void **)&del->tab);
			ft_strdel(&del->u);
			ft_memdel((void **)&del);
		}
	}
}

void	fDataCouples(t_couple **ptr, t_couple *del, t_couple *lst)
{
	while (lst)
	{
		del = lst;
		lst = lst->n;
		ft_memdel((void **)&del);
	}
	(*ptr) = NULL;
}

void	fDataBox(t_data *d)
{
	t_pBox		*lst;
	t_pBox		*del;

	if (d && d->box)
	{
		lst = d->box;
		while (lst)
		{
			del = lst;
			lst = lst->n;
			if (del->links)
				fDataLink(del->links);
			ft_strdel(&del->name);
			ft_memdel((void **)&del);
		}
	}
	if (d->couples)
		fDataCouples(&d->couples, (t_couple *)NULL, d->couples);
	if (d->solution)
		fDataCouples(&d->solution, (t_couple *)NULL, d->solution);
	if (d->p)
		fDataCouples(&d->solution, (t_couple *)NULL, d->p);
	fDataRoads(d);
}
