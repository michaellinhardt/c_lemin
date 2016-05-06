/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_prun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:50:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/06 16:41:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_pBox		*pBox(t_pBox *root, char *l)
{
	t_pBox_tmp	s;

	ft_bzero(&s, sizeof(t_pBox_tmp));
	// lis le fichier ligne par ligne, en commencant après le nb fourmis
	while (ft_strdel(&l) && get_next_line(0, &l))
	{
		// stop si débute avec L ou ligne vide
		(!*l || *l == 'L') ? eExit2(1, l) : 1;
		// detect les commande start & end & commentaires & régle le type de la box suivante
		if (!ft_strcmp(l, "##start") && (s.type = 1))
			(s.start) ? eExit2(1, l) : (s.start = 1) ;
		else if (!ft_strcmp(l, "##end") && (s.type = 2))
			(s.end) ? eExit2(1, l) : (s.end = 1) ;
		else if (!(s.type = 0) && l[0] != '#')
		{
			//ici on a une ligne a parse,
			// elle n'est ni un commentaire ni une ligne débutant par L
			ft_printf("%s\n", l);
		}
	}
	return (root);
}

int			pAnts(void)
{
	char	*line;
	char	*verif;
	int		ants;

	// réglé a NULL pour gérer les fichier vide
	line = (char *)NULL;
	verif = (char *)NULL;
	// saute les commentaires en entré de fichiers et régle verif
	while (get_next_line(0, &line))
		if (*line != '#' && (verif = line))
			break;
		else
			ft_strdel(&line);
	// control si la ligne contiens que des chiffre
	while (line && *verif && ft_isdigit(*verif))
		verif++;
	// pour gagner des ligne on stock tte suite ants et on free
	ants = (line && (!*verif)) ? ft_atoi(line) : -1;
	ft_strdel(&line);
	// on return ants ou on stop si erreur
	return ((ants > 0) ? ants : eExit(1));
}

void		pRun(t_data *d)
{
	d->ants = pAnts(); // parse le nombre de fourmis
	d->box = pBox((t_pBox *)NULL, (char *)NULL); // créer la liste des box
	get_next_line(-10, NULL);
}
