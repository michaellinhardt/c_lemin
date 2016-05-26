/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_couples.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 23:20:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 01:33:07 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		iCouplesStruct(t_data *d, t_couple *new, int i, t_couple **ptr)
{
	while (++i <= d->roadsmax)
	{
		if (!(new = (t_couple *)ft_memalloc(sizeof(t_couple))))
			eExit(1, d, "Cant malloc.");
		new->r = d->roads;
		if (!(*ptr) && !(new->n = NULL))
		{
			new->p = NULL;
			(*ptr) = new;
		}
		else if (((*ptr)->p = new))
		{
			new->n = (*ptr);
			(*ptr) = new;
		}
	}
}

void		iMaxroads(t_data *d, int i, t_pBoxLink *lst)
{
	d->roadsmax = d->idbox;
	lst = d->start->links;
	while (lst && ++i)
		lst = lst->n;
	d->roadsmax = (i < d->roadsmax) ? i : d->roadsmax;
	i = 0;
	lst = d->end->links;
	while (lst && ++i)
		lst = lst->n;
	d->roadsmax = (i < d->roadsmax) ? i : d->roadsmax;
}

int			iCouples(t_data *d)
{
	iMaxroads(d, 0, (t_pBoxLink *)NULL);
	iCouplesStruct(d, (t_couple *)NULL, 0, &d->solution);
	iCouplesStruct(d, (t_couple *)NULL, 0, &d->couples);
	return (0);
}
