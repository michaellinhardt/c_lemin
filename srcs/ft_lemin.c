/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 17:29:09 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	iAlgo(t_data *data, char *used)
{
	data->couples = NULL;
	data->solution = NULL;
	data->p = NULL;
	data->roads = NULL;
	data->i = 0;
	iRoads(data, (t_roads *)NULL, (t_pBox **)NULL, (char *)NULL);
	if (data->idbox <= 200)
	{
		rRoads(data, data->start, used, 0);
		fRoadsLast(data);
		if (!data->roads)
			eExit2(1, data, used, "No roads.");
		iCouples(data);
	}
	else
	{
		data->roadsmax = 1;
		data->start->sizeok = 1;
		data->end->sizeok = 1;
		rSize(data, 1, data->end->links, data->end->links);
		iSizeRoad(data, data->start, data->start->links, data->roads);
		iCouplesStruct(data, (t_couple *)NULL, 0, &data->solution);
		data->solution->r = data->roads;
	}
}

int		main(void)
{
	t_data		data;
	char		*used;

	pAscii();
	ft_bzero(&data, sizeof(t_data));
	pRun(&data);
	if (!(used = ft_strnew((data.idbox + 1))))
		eExit(1, &data, "Can't malloc.");
	iAlgo(&data, used);
	if (!data.roads)
		eExit2(1, &data, used, "No roads.");
	pAsciiClose();
	pAsciiOpen(1);
	oData(&data);
	pAsciiMsg("Chemin utilisé:", 7);
	pAsciiClose();
	data.ret = 0;
	data.tmax = data.ants;
	data.rendmax = 0;
	oPrint(&data, data.p, (t_roads *)NULL, 0);
	ft_strdel(&used);
	fDataBox(&data);
	return (0);
}
