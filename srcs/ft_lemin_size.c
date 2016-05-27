/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 09:28:40 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 18:14:54 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	rsize(t_data *d, int s, t_pboxlink *lnk, t_pboxlink *root)
{
	while (lnk)
	{
		if (lnk->link != d->start && lnk->link != d->end &&
			(lnk->link->size == 0 || lnk->link->size > s))
			lnk->link->size = s;
		lnk = lnk->n;
	}
	lnk = root;
	while (lnk)
	{
		if (lnk->link->sizeok == 0 && (lnk->link->sizeok = 1))
			rsize(d, (s + 1), lnk->link->links, lnk->link->links);
		lnk = lnk->n;
	}
}

void	isizeroad(t_data *d, t_pbox *next, t_pboxlink *lnk, t_roads *road)
{
	int			i;
	int			s;

	i = -1;
	while (42)
	{
		road->tab[++i] = next;
		if (i > 0 && road->tab[i] == road->tab[(i - 1)])
			eexit(1, d, "No roads.");
		if (next == d->end && ((road->score = i) || 1))
			return ;
		lnk = next->links;
		s = INT_MAX;
		while (lnk)
		{
			if ((lnk->link == d->end && !(s = 0)) || (lnk->link->sizeok != -1 &&
			lnk->link->size && lnk->link->size <= s && (s = lnk->link->size)))
			{
				lnk->link->sizeok = -1;
				next = lnk->link;
			}
			lnk = lnk->n;
		}
	}
}
