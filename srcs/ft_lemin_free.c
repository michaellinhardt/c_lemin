/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 20:02:45 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/21 18:17:32 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	fDataLink(t_pBoxLink *lst)
{
	t_pBoxLink	*del;

	while (lst)
	{
		del = lst;
		lst = lst->n;
		ft_memdel((void **)&del);
	}
}

void	fDataBox(t_data *d)
{
	t_pBox		*lst;
	t_pBox		*del;

	if (d && d->box)
	{
		lst = d->box;
		while (lst)
		{
			del = lst;
			lst = lst->n;
			if (del->links)
				fDataLink(del->links);
			ft_strdel(&del->name);
			ft_memdel((void **)&del);
		}
	}

}
