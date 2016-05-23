/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_addlink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:57:03 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/23 17:10:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		dLinkAdd(t_pBox *b1, t_pBox *b2, t_pBoxLink *l1)
{
	t_pBoxLink *l;

	l1->link = b2;
	if (!(l = b1->links))
		b1->links = l1;
	else
	{
		while (l)
		{
			if (l->link->name == l1->link->name && ft_memdel((void **)&l1))
				break ;
			if (!l->n && (l->n = l1))
				break ;
			l = l->n;
		}
	}
}

int			dLinkVerif(char n1[4096], char n2[4096], t_pBox	*lst, t_pBox *b1)
{
	t_pBox		*b2;
	t_pBoxLink	*l1;
	t_pBoxLink	*l2;

	b2 = NULL;
	while (lst)
	{
		if (!ft_strcmp(n1, lst->name))
			b1 = lst;
		else if (!ft_strcmp(n2, lst->name))
			b2 = lst;
		lst = lst->n;
	}
	if (b1 && b2)
	{
		if (!(l1 = (t_pBoxLink *)ft_memalloc(sizeof(t_pBoxLink))))
			return (1);
		if (!(l2 = (t_pBoxLink *)ft_memalloc(sizeof(t_pBoxLink))))
			return (1);
		dLinkAdd(b1, b2, l1);
		dLinkAdd(b2, b1, l2);
		return (0);
	}
	return (1);
}

int			dLink(t_data *d, char *l, int i, int j)
{
	char	n1[4096];
	char	n2[4096];

	ft_bzero(n1, (sizeof(char) * 4096));
	ft_bzero(n2, (sizeof(char) * 4096));
	while (l[++i] && l[i] != '-')
		n1[i] = l[i];
	while (l[++i])
		n2[++j] = l[i];
	// ici on a une erreur, on stop le parsing et on démarre l'algo
	if (dLinkVerif(n1, n2, d->box, (t_pBox *)NULL))
		return (1);
	return (0);
}
