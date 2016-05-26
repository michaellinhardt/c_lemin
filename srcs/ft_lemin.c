/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/26 03:30:18 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		main(void)
{
	t_data		data;
	char		*used;

	pAscii();
	ft_bzero(&data, sizeof(t_data));
	pRun(&data);
	if (!(used = ft_strnew((data.idbox + 1))))
		eExit(1, &data, "Can't malloc.");
	data.roads = NULL;
	data.i = 0;
	iRoads(&data, (t_roads *)NULL, (t_pBox **)NULL, (char *)NULL);
	rRoads(&data, data.start, used, 0);
	fRoadsLast(&data);
	if (!data.roads)
		eExit2(1, &data, used, "No roads.");
	oData(&data);
	pAsciiClose();



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
if (data.roads)
{
	t_roads *roads = data.roads; int j;
	while (roads)
	{
		ft_printf("(ID. %2d)[Poid. %2d] ", roads->id, roads->score);
		j = -1;
		while (roads->tab[++j])
			ft_printf("-> (%d)%s ", roads->tab[j]->id, roads->tab[j]->name);
		ft_printf("\n%18s", "used box id: ");
		i = -1;
		while (++i < (data.idbox + 1))
			if (roads->u[i] == 1)
				ft_printf("[%d] ", i);
		ft_printf("\n\n");
		roads = roads->n;
	}
} else { ft_printf("pas de route\n"); }





	ft_strdel(&used);
	fDataBox(&data);
	return (0);
}
