/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_prun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:50:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/05 05:18:13 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_pBox		*pBox(void)
{
	return ((t_pBox *)NULL);
}

int			pAnts(void)
{
	char	*line;
	char	*verif;
	int		ants;

	// saute les commentaires en entré de fichiers et régle verif
	while (get_next_line(0, &line))
		if (*line != '#' && (verif = line))
			break;
		else
			ft_strdel(&line);
	// control si la ligne contiens que des chiffre
	while (*verif && ft_isdigit(*verif))
		verif++;
	// pour gagner des ligne on stock tte suite ants et on free
	ants = (line && (!*verif)) ? ft_atoi(line) : -1;
	ft_strdel(&line);
	// on return ants ou on stop si erreur
	return ((ants > 0) ? ants : eExit(1));
}

void		pRun(t_data *d)
{
	d->ants = pAnts();
	ft_printf("ants: %d\n", d->ants);
	d->box = pBox();
	get_next_line(-10, NULL);

	// while (get_next_line(0, &line))
	// 	(ft_printf("%s\n", line) || 1) ? ft_strdel(&line) : 1;
	// ft_strdel(&line);
}
