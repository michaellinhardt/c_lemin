/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 20:02:45 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 14:20:13 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	froadslast(t_data *d)
{
	t_roads		*del;

	del = d->roads;
	if (del->score == 0)
	{
		ft_memdel((void **)&del->tab);
		d->roads = (del->n) ? del->n : NULL;
		ft_strdel(&del->u);
		ft_memdel((void **)&del);
		d->nbroads--;
	}
}

void	fdatalink(t_pboxlink *lst)
{
	t_pboxlink	*del;

	while (lst)
	{
		del = lst;
		lst = lst->n;
		ft_memdel((void **)&del);
	}
}

void	fdataroads(t_data *d)
{
	t_roads		*lst;
	t_roads		*del;

	if (d && d->roads)
	{
		lst = d->roads;
		while (lst)
		{
			del = lst;
			lst = lst->n;
			ft_memdel((void **)&del->tab);
			ft_strdel(&del->u);
			ft_memdel((void **)&del);
		}
	}
}

void	fdatacouples(t_couple **ptr, t_couple *del, t_couple *lst)
{
	while (lst)
	{
		del = lst;
		lst = lst->n;
		ft_memdel((void **)&del);
	}
	(*ptr) = NULL;
}

void	fdatabox(t_data *d)
{
	t_pbox		*lst;
	t_pbox		*del;

	if (d && d->box)
	{
		lst = d->box;
		while (lst)
		{
			del = lst;
			lst = lst->n;
			if (del->links)
				fdatalink(del->links);
			ft_strdel(&del->name);
			ft_memdel((void **)&del);
		}
	}
	if (d->couples)
		fdatacouples(&d->couples, (t_couple *)NULL, d->couples);
	if (d->solution)
		fdatacouples(&d->solution, (t_couple *)NULL, d->solution);
	if (d->p)
		fdatacouples(&d->solution, (t_couple *)NULL, d->p);
	fdataroads(d);
}
