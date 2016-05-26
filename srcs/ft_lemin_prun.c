/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_prun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:50:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/26 03:36:15 by mlinhard         ###   ########.fr       */
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
	if (!space && tiret == 1)
		return (2);
	else if (!space && tiret != 1)
		return (0);
	else if (space == 2)
		return (1);
	else
		return (0);
}

int			pReadWhile(t_data *d, char *l, t_pRead *s)
{
	((!*l || *l == 'L') &&
	!s->step) ? eExit2(1, d, l, "Line empty or start with L.") : 1;
	if (!ft_strcmp(l, "##start") && (s->type = 1))
		(s->start) ? eExit2(1, d, l, "Duplicated ##start.") : (s->start = 1);
	else if (!ft_strcmp(l, "##end") && (s->type = 2))
		(s->end) ? eExit2(1, d, l, "Duplicated ##end.") : (s->end = 1);
	else if (l[0] != '#')
	{
		if ((!(s->j = pType(l)) && !s->step) || (s->j == 2 && !d->box))
			eExit2(1, d, l, "Bad line or link before box.");
		else if (s->j == 1 && !s->step)
			dBox(d, l, -1, s->type);
		else if (((s->j == 1 || !s->j) && s->step == 1) ||
				((s->j == 2 && (s->step = 1)) && dLink(d, l, -1, -1)) ||
				(s->step && (!*l || *l == 'L')))
			return (1);
		s->type = 0;
	}
	return (0);
}

void		pRead(t_data *d, char *l)
{
	t_pRead		s;

	ft_bzero(&s, sizeof(t_pRead));
	while (ft_strdel(&l) && get_next_line(0, &l))
		if (pReadWhile(d, l, &s))
			break ;
	if (ft_strdel(&l) && !d->box)
		eExit(1, d, "You forget the box.");
}

int			pAnts(t_data *d, char *line, char *verif, int ants)
{
	size_t		len;

	len = 0;
	while (ft_strdel(&line) && (get_next_line(0, &line)) > 0)
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			eExit2(1, d, line, "Start/end before ants.");
		if (*line != '#' && (verif = line))
			break;
	}
	if (!line)
		eExit2(1, d, line, "Can't read input map.");
	while (line && *verif && ft_isdigit(*verif))
		verif++;
	if ((len = ft_strlen(line)) > 10)
		eExit2(1, d, line, "Ants cant overflow Int max.");
	else if (len == 10 && ft_atoimax(line) > INT_MAX)
		eExit2(1, d, line, "Ants cant overflow Int max.");
	ants = (line && (!*verif)) ? ft_atoi(line) : -1;
	ft_strdel(&line);
	return ((ants > 0) ? ants : eExit(1, d, "Where are ants ?"));
}

void		pRun(t_data *d)
{
	d->ants = pAnts(d, (char *)NULL, (char *)NULL, -1);
	d->start = NULL;
	d->end = NULL;
	d->idbox = 1;
	pRead(d, (char *)NULL);
	if (!d->start || !d->end)
		eExit(1, d, "Start/end box missing.");
	get_next_line(-10, NULL);
}
