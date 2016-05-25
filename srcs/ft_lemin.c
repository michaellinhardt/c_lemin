/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/25 16:39:04 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		main(void)
{
	t_data		data;
	char		*used;

	ft_bzero(&data, sizeof(t_data));
	pRun(&data);
	if (!(used = ft_strnew((data.idbox + 1))))
		eExit(1, &data);
	data.roads = NULL;
	data.i = 0;
	iRoads(&data, (t_roads *)NULL, (t_pBox **)NULL);
	rRoads(&data, data.start, used, 0);


// DEBUG LISTING DES BOX
ft_printf("fourmis: %d\n", data.ants);
int i; t_pBoxLink *link; t_pBox *box = data.box; while (box)
{ ft_printf("(%d)[n%d, %s] %d %d\n", box->type, box->id, box->name, box->x, box->y);
	if (box->links)
	{
		link = box->links;
		i = 0; while (link && ++i)
		{
			ft_printf("tube %d: %s\n", i, (link->link)->name);
			link = link->n;
		}
	} box = box->n; }



// DEBUG LIST CHEMIN
t_roads *roads = data.roads; int j;
while (roads)
{
	ft_printf("(ID. %2d)[Poid. %2d] ", roads->id, roads->score);
	j = -1;
	while (roads->tab[++j])
		ft_printf("-> %s ", roads->tab[j]->name);
	ft_printf("\n");
	roads = roads->n;
}





	ft_strdel(&used);
	fDataBox(&data);
	return (0);
}
