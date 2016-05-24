/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_prun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:50:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/24 16:20:01 by mlinhard         ###   ########.fr       */
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
	else if (space == 2)
		return (1);
	// sinon erreur
	else
		return (0);
}

void		pRead(t_data *d, char *l)
{
	t_pRead		s;

	ft_bzero(&s, sizeof(t_pRead));
	while (ft_strdel(&l) && get_next_line(0, &l))
	{
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
			if ((!(s.j = pType(l)) && !s.step) || (s.j == 2 && !d->box))
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
	// Si on a aucune box
	if (!d->box)
		eExit(1, d);
}

int			pAnts(char	*line, char	*verif, int ants, size_t len)
{
	while (ft_strdel(&line) && (get_next_line(0, &line)) > 0)
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			eExit2(1, (t_data *)NULL, line);
		if (*line != '#' && (verif = line))
			break;
	}
	if (!line)
		eExit2(1, (t_data *)NULL, line);
	// control si la ligne contiens que des chiffre
	while (line && *verif && ft_isdigit(*verif))
		verif++;
	if ((len = ft_strlen(line)) > 10)
		eExit2(1, (t_data *)NULL, line);
	else if (len == 10 && ft_atoimax(line) > INT_MAX)
		eExit2(1, (t_data *)NULL, line);
	// on stock tte suite ants et on free
	ants = (line && (!*verif)) ? ft_atoi(line) : -1;
	ft_strdel(&line);
	// on return ants ou on stop si erreur
	return ((ants > 0) ? ants : eExit(1, (t_data *)NULL));
}

void		pRun(t_data *d)
{
	d->ants = pAnts((char *)NULL, (char *)NULL, -1, 0);
	d->start = NULL;
	d->end = NULL;
	pRead(d, (char *)NULL);
	if (!d->start || !d->end)
		eExit(1, d);

// DEBUG LISTING DES BOX
	ft_printf("fourmis: %d\n", d->ants);
	int i; t_pBoxLink *link; t_pBox *box = d->box; while (box)
	{ ft_printf("(%d)[n%d, %s] %d %d\n", box->type, box->id, box->name, box->x, box->y);
		if (box->links)
		{
			link = box->links;
			i = 0; while (link && ++i)
			{
				ft_printf("tube %d: %s\n", i, (link->link)->name);
				link = link->n;
			}
		} box = box->n; }


	get_next_line(-10, NULL);
}
