/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_roads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:25:02 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/25 19:34:26 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int			iRoads(t_data *d, t_roads *new, t_pBox **tab, char *u)
{
	int		size;
	char	*u2;

	size = (d->idbox + 3);
	if (!(new = (t_roads *)ft_memalloc(sizeof(t_roads))))
		return (1);
	if (!(tab = (t_pBox **)ft_memalloc(sizeof(t_pBox *) * (size))))
		return (1);
	if (!(u2 = ft_strnew((d->idbox + 1))))
		return (1);
	if (d->roads)
		ft_memcpy(d->roads->u, u, (sizeof(char) * (d->idbox + 1)));
	if (d->roads)
		ft_memcpy(tab, d->roads->tab, (sizeof(t_pBox *) * (size)));
	while (!d->roads && size--)
		tab[size] = (t_pBox *)NULL;
	new->u = u2;
	new->tab = tab;
	new->n = d->roads;
	new->id = ++d->i;
	d->roads = new;
	return (0);
}

void		rRoads(t_data *d, t_pBox *box, char *used, int i)
{
	t_pBoxLink *lnk;

	lnk = box->links;
	used[box->id] = 1;
	d->roads->tab[i] = box;
	while (lnk)
	{
		if (lnk->link->type == 2)
		{
			d->roads->score = (i + 1);
			d->roads->tab[(i + 1)] = lnk->link;
			d->roads->tab[(i + 2)] = NULL;
			iRoads(d, (t_roads *)NULL, (t_pBox **)NULL, used);
		}
		else if (!used[lnk->link->id])
			rRoads(d, lnk->link, used, (i + 1));
		lnk = lnk->n;
	}
	d->roads->tab[i] = (t_pBox *)NULL;
	used[box->id] = 0;
}
