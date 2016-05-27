/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_icouples.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 23:20:04 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 06:57:37 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		icouplesstruct(t_data *d, t_couple *new, int i, t_couple **ptr)
{
	while (++i <= d->roadsmax)
	{
		if (!(new = (t_couple *)ft_memalloc(sizeof(t_couple))))
			eexit(1, d, "Cant malloc.");
		new->r = NULL;
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

void		imaxroads(t_data *d, int i, t_pboxlink *lst)
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

int			icouples(t_data *d)
{
	imaxroads(d, 0, (t_pboxlink *)NULL);
	icouplesstruct(d, (t_couple *)NULL, 0, &d->solution);
	icouplesstruct(d, (t_couple *)NULL, 0, &d->couples);
	d->solution->score = INT_MAX;
	rcouples(d, (d->roadsmax + 1), (t_couple *)NULL);
	return (0);
}
