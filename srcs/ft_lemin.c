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

void	ialgo(t_data *data, char *used)
{
	data->couples = NULL;
	data->solution = NULL;
	data->p = NULL;
	data->roads = NULL;
	data->i = 0;
	iroads(data, (t_roads *)NULL, (t_pBox **)NULL, (char *)NULL);
	if (data->idbox <= 200)
	{
		rroads(data, data->start, used, 0);
		froadslast(data);
		if (!data->roads)
			eexit2(1, data, used, "No roads.");
		icouples(data);
	}
	else
	{
		data->roadsmax = 1;
		data->start->sizeok = 1;
		data->end->sizeok = 1;
		rSize(data, 1, data->end->links, data->end->links);
		iSizeRoad(data, data->start, data->start->links, data->roads);
		icouplesstruct(data, (t_couple *)NULL, 0, &data->solution);
		data->solution->r = data->roads;
	}
}

int		main(void)
{
	t_data		data;
	char		*used;

	pascii();
	ft_bzero(&data, sizeof(t_data));
	prun(&data);
	if (!(used = ft_strnew((data.idbox + 1))))
		eexit(1, &data, "Can't malloc.");
	ialgo(&data, used);
	if (!data.roads)
		eexit2(1, &data, used, "No roads.");
	pasciiclose();
	pasciiopen(1);
	odata(&data);
	pasciimsg("Chemin utilisé:", 7);
	pasciiclose();
	data.ret = 0;
	data.tmax = data.ants;
	data.rendmax = 0;
	oprint(&data, data.p, (t_roads *)NULL, 0);
	ft_strdel(&used);
	fdatabox(&data);
	return (0);
}
