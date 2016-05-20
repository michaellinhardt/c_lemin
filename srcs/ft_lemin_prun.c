/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_prun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:50:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/20 18:11:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

char		pType(char *l)
{
	int		space;
	int		tiret;
	int		i;

	space = 0;
	tiret = 0;
	i = -1;
	while (l[++i])
	{
		space += (l[i] == ' ') ? 1 : 0;
		tiret += (l[i] == '-') ? 1 : 0;
	}
	// Pas d'espace et 1 tiret = lien
	if (!space && tiret == 1)
		return (2);
	// pas d'espace et tiret != 1 = erreur
	else if (!space && tiret != 1)
		return (0);
	// 2 espace = box
	else if (space == 2 && !tiret)
		return (1);
	// sinon erreur
	else
		return (0);
}

void		pRead(t_data *d, char *l)
{
	t_pRead		s;

	(void)d;
	ft_bzero(&s, sizeof(t_pRead));
	// lis le fichier ligne par ligne, en commencant après le nb fourmis
	while (ft_strdel(&l) && get_next_line(0, &l))
	{
		// stop si débute avec L ou ligne vide
		((!*l || *l == 'L') && !s.step) ? eExit2(1, d, l) : 1;
		// detect les commande start & end & commentaires & régle le type de la box suivante
		if (!ft_strcmp(l, "##start") && (s.type = 1))
			(s.start) ? eExit2(1, d, l) : (s.start = 1);
		else if (!ft_strcmp(l, "##end") && (s.type = 2))
			(s.end) ? eExit2(1, d, l) : (s.end = 1);
		else if (l[0] != '#')
		{
			//ici on a une ligne a parse, elle n'est ni un commentaire ni une ligne débutant par L
			// On vérifie si c'est bien une box
			// On stop si on à une ligne invalide et que step = 0, ce qui signifie qu'on à aucun lien pour le moment
			if (!(s.j = pType(l)) && !s.step)
				eExit2(1, d, l);
			else if (s.j == 1 && !s.step)
				dBox(d, l, -1, s.type);
				// si on trouve autre chose qu'un lien pendant la lecture des lien
			else if (((s.j == 1 || !s.j) && s.step == 1) ||
				// si on à un lien qui est invalidé par dLink
					((s.j == 2 && (s.step = 1)) && dLink(d, l, -1, -1)) ||
				// Si on a une ligne vide ou débutant par L pendant la lecture des lien
					(s.step && (!*l || *l == 'L')))
				break ;
			s.type = 0;
		}
	}
	ft_strdel(&l);
	ft_printf("fin du parsing, lancement de l'algo\n");
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
	return ((ants > 0) ? ants : eExit(1, (t_data *)NULL));
}

void		pRun(t_data *d)
{
	t_pBox	*box;

	d->ants = pAnts(); // parse le nombre de fourmis
	pRead(d, (char *)NULL); // créer la liste des box


// DEBUG LISTING DES BOX
	box = d->box; while (box)
	{ ft_printf("(%d)[%s] %d %d\n", box->type, box->name, box->x, box->y);
		box = box->n; }


	get_next_line(-10, NULL);
}
