/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_addlink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:57:03 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/20 18:00:01 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		dLinkAdd(t_data *d, char n1[4096], char n2[4096])
{
	ft_printf("(%d)Ajout de lien: %s - %s\n", d->ants, n1, n2);
}

int			dLinkVerif(t_data *d, char n1[4096], char n2[4096])
{
	int		verif[2];
	t_pBox	*lst;

	verif[0] = 0;
	verif[1] = 0;
	lst = d->box;
	while (lst)
	{
		if (!ft_strcmp(n1, lst->name))
			verif[0] = 1;
		else if (!ft_strcmp(n2, lst->name))
			verif[1] = 1;
		lst = lst->n;
	}
	if (verif[0] == verif[1] == 1)
		return (0);
	else
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
	if (dLinkVerif(d, n1, n2))
		return (1);
	dLinkAdd(d, n1, n2);
	return (0);
}
