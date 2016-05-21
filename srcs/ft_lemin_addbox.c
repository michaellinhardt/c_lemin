/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_addbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:43:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/21 20:10:14 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int			dBoxCheck(t_data *d, char name[4096], int x, int y)
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

int			dBoxAdd(t_data *d, char nom[4096], char x[12], char y[12])
{
	t_pBox	*new;
	t_pBox	*lst;
	char	*name;

	if (dBoxCheck(d, nom, ft_atoi(x), ft_atoi(y)) || !(name = ft_strnew(4096)))
		return (1);
	name = ft_memcpy(name, nom, 4096);
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
	new->name = name;
	if ((new->type = d->i) == 1)
		d->start = new;
	else if (d->i == 2)
		d->end = new;
	new->x = ft_atoi(x);
	new->y = ft_atoi(y);
	return (0);
}

void		dBox(t_data *d, char *l, int i, char type)
{
	char	coord[12];
	char	coord2[12];
	char	name[4096];
	int		j;

	while ((j = -1) && l[++i] && l[i] != ' ')
		name[i] = l[i];
	name[i] = '\0';
	while (l[++i] && l[i] != ' ')
	{
		if (!ft_isdigit(l[i]))
			eExit2(1, d, l);
		coord[++j] = l[i];
	}
	coord[++j] = '\0';
	j = -1;
	while (((d->i = type) || 1) && l[++i])
	{
		if (!ft_isdigit(l[i]))
			eExit2(1, d, l);
		coord2[++j] = l[i];
	}
	coord2[++j] = '\0';
	if (dBoxAdd(d, name, coord, coord2))
		eExit2(1, d, l);
}
