/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 02:14:44 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/26 04:24:11 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	oData(t_data *d)
{
	ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 "🐛  Fourmis: ", d->ants);
	ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 "🗃  Box: ", d->idbox);
	ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 "🛤  Chemins valide: ", d->nbroads);
	ft_printf("\e[93m  | \e[39m%-40s%35s\e[93m  |\e[39m\n",
	 "🏁  Start: ", ((d->start) ? d->start->name : "unknow"));
	ft_printf("\e[93m  | \e[39m%-40s%35s\e[93m  |\e[39m\n",
	 "🏠  End: ", ((d->end) ? d->end->name : "unknow"));



	pAsciiClose();
	pAsciiOpen();
}
