/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_roads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:25:02 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/24 17:56:29 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_roads		*rRoads(t_data *d, t_pBox *box, char *used, t_pBoxLink *lnk)
{
	// pour enregistrer le chemin
	t_roads		*road = NULL; d->idbox += 0; (void)road;

	// écris cette box comme utilisé
	used[box->id] = 1;
	ft_printf("RECURSION START SUR: [%s]\n", box->name);
	while (lnk)
	{
		if (lnk->link->type == 2)
		{
			ft_printf("ARRIVé SUR: [%s]\n\n", lnk->link->name);
		}
		else if (!used[lnk->link->id])
		{
			ft_printf("*Relance: [%s] vers [%s]\n", box->name, lnk->link->name);
			rRoads(d, lnk->link, used, lnk->link->links);
		}
		lnk = lnk->n;
	}
	used[box->id] = 0;
	// ft_printf("RECURSION OVER SUR: [%s]\n", box->name);
	return ((t_roads *)1);
}
