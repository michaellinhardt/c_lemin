/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_addbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:43:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/23 22:30:36 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int			dBoxCheck(t_data *d, char *name, int x, int y)
{
	t_pBox	*lst;

	lst = d->box;
	while (lst)
	{
		if (!ft_strcmp(lst->name, name) || (x == lst->x && y == lst->y))
			return (1);
		lst = lst->n;
	}
	return (0);
}

int			dBoxAdd(t_data *d, char *name, int x, int y)
{
	t_pBox	*new;
	t_pBox	*lst;

	if (!(new = (t_pBox *)ft_memalloc(sizeof(t_pBox))))
		return (1);
	if (!d->box)
		d->box = new;
	else
	{
		lst = d->box;
		while (lst->n)
			lst = lst->n;
		lst->n = new;
	}
	new->links = NULL;
	new->n = NULL;
	new->name = name;
	if ((new->type = d->i) == 1)
		d->start = new;
	else if (d->i == 2)
		d->end = new;
	new->x = x;
	new->y = y;
	return (0);
}

int			dBoxCoord(t_data *d, char *l, char c, int len)
{
	char		coord[12];
	intmax_t	icoord;
	int			j;

	j = -1;
	if (l[(d->i + 1)] == '-' && ++len && (coord[++j] = '-'))
		d->i++;
	while (l[++d->i] && l[d->i] != c && ++len < 12)
	{
		if (!ft_isdigit(l[d->i]))
			return ((d->ret = -1));
		coord[++j] = l[d->i];
	}
	if (len == 12 && l[d->i] != c)
		return ((d->ret = -1));
	coord[++j] = '\0';
	icoord = ft_atoimax(coord);
	if (len == 0 ||
		(icoord < 0 && icoord < INT_MIN) || (icoord > 0 && icoord > INT_MAX))
		return ((d->ret = -1));
	return ((int)icoord);
}

void		dBox(t_data *d, char *l, int x, char type)
{
	int		y;
	char	*name;

	d->i = -1;
	while (l[++d->i] && l[d->i] != ' ')
		if (l[d->i] == '-')
			eExit2(1, d, l);
	if (l[d->i])
		name = ft_strsub(l, 0, d->i);
	else
		eExit2(1, d, l);
	if (d->i == 0)
		eExit2(1, d, l);
	d->ret = 0;
	x = dBoxCoord(d, l, ' ', 0);
	y = dBoxCoord(d, l, '\0', 0);
	d->i = type;
	if ((d->ret == -1) || dBoxCheck(d, name, x, y) || dBoxAdd(d, name, x, y))
	{
		ft_strdel(&name);
		eExit2(1, d, l);
	}
}
