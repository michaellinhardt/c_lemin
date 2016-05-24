/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/24 17:22:10 by mlinhard         ###   ########.fr       */
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
	if (!rRoads(&data, data.start, used, data.start->links))
		eExit(1, &data);
ft_strdel(&used);
	fDataBox(&data);
	return (0);
}
