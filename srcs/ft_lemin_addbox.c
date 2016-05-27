/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_addbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:43:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 18:01:02 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int			dboxcheck(t_data *d, char *name, int x, int y)
{
	t_pbox	*lst;

	lst = d->box;
	while (lst)
	{
		if (!ft_strcmp(lst->name, name) || (x == lst->x && y == lst->y))
			return (1);
		lst = lst->n;
	}
	return (0);
}

int			dboxadd(t_data *d, char *name, int x, int y)
{
	t_pbox	*new;

	if (!(new = (t_pbox *)ft_memalloc(sizeof(t_pbox))))
		return (1);
	if (!d->box)
		d->box = new;
	else if ((new->n = d->box) || 1)
		d->box = new;
	new->links = NULL;
	new->name = name;
	if ((new->type = d->i) == 1)
		d->start = new;
	else if (d->i == 2)
		d->end = new;
	new->size = 0;
	new->sizeok = 0;
	new->id = d->idbox++;
	new->x = x;
	new->y = y;
	return (0);
}

int			dboxcoord(t_data *d, char *l, char c, int len)
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

void		dboxoutput(char type, char *l)
{
	if (type == 0)
		pasciimsg(l, 2);
	else if (type == 1)
		pasciimsg(l, 8);
	else if (type == 2)
		pasciimsg(l, 9);
}

void		dbox(t_data *d, char *l, int x, char type)
{
	int		y;
	char	*name;

	d->i = -1;
	while (l[++d->i] && l[d->i] != ' ')
		if (l[d->i] == '-' && !pasciimsg(l, 1))
			eexit2(1, d, l, "Dont use - in box name please.");
	if (l[d->i])
		name = ft_strsub(l, 0, d->i);
	else if (!pasciimsg(l, 1))
		eexit2(1, d, l, "Missing box name.");
	if (d->i == 0 && !pasciimsg(l, 1))
		eexit2(1, d, l, "You forget the box name.");
	d->ret = 0;
	x = dboxcoord(d, l, ' ', 0);
	y = dboxcoord(d, l, '\0', 0);
	d->i = type;
	if ((d->ret == -1) || dboxcheck(d, name, x, y) || dboxadd(d, name, x, y))
	{
		pasciimsg(l, 1);
		ft_strdel(&name);
		eexit2(1, d, l, "Bad box informations.");
	}
	dboxoutput(type, l);
}
