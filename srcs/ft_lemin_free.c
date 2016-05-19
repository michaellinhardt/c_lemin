/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 20:02:45 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/19 20:05:34 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	fDataBox(t_data *d)
{
	t_pBox *lst;
	t_pBox *del;

	lst = d->box;
	while (lst)
	{
		del = lst;
		lst = lst->n;
		ft_strdel(&del->name);
		ft_memdel((void **)&del);
	}
}
