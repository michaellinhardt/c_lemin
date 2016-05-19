/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:43:43 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/19 21:59:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		dBoxAdd(t_data *d, char nom[4096], char x[12], char y[12])
{
	t_pBox	*new;
	t_pBox	*lst;
	char	*name;

	if (!(name = ft_strnew(4096)))
		eExit(1, d);
	name = ft_memcpy(name, nom, 4096);
	if (!(new = (t_pBox *)malloc(sizeof(t_pBox))))
		eExit(1, d);
	ft_bzero(new, sizeof(t_pBox));
	if (!d->box)
		d->box = new;
	else
	{
		lst = d->box;
		while (lst->n)
			lst = lst->n;
		lst->n = new;
	}
	new->name = name;
	new->type = d->i;
	new->x = ft_atoi(x);
	new->y = ft_atoi(y);
}

void	dBox(t_data *d, char *l, int i, char type)
{
	char	coord[12];
	char	coord2[12];
	char	name[4096];
	int		j;

	ft_bzero(name, (sizeof(char) * 4096));
	while ((j = -1) && l[++i] && l[i] != ' ')
		name[i] = l[i];
	ft_bzero(&coord, (sizeof(char) * 12));
	ft_bzero(&coord2, (sizeof(char) * 12));
	while (l[++i] && l[i] != ' ')
	{
		if (!ft_isdigit(l[i]))
			eExit2(1, d, l);
		coord[++j] = l[i];
	}
	j = -1;
	while (l[++i])
	{
		if (!ft_isdigit(l[i]))
			eExit2(1, d, l);
		coord2[++j] = l[i];
	}
	d->i = type;
	dBoxAdd(d, name, coord, coord2);
}
