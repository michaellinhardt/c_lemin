/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 02:14:44 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/26 06:47:49 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		oAnts(char *line)
{
	size_t		len;
	char		*verif;

	len = 0;
	verif = line;
	while (line && *verif && ft_isdigit(*verif))
		verif++;
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		pAsciiMsg(line, 1);
	else if (*line == '#')
		pAsciiMsg(line, 5);
	else if (!line)
		pAsciiMsg("(get_next_line return NULL for line)", 5);
	else if ((len = ft_strlen(line)) > 10)
		pAsciiMsg(line, 1);
	else if (len == 10 && ft_atoimax(line) > INT_MAX)
		pAsciiMsg(line, 1);
	else if (line && (!*verif))
		pAsciiMsg(line, 6);
	else
		pAsciiMsg(line, 1);
	return (0);
}

void	oMap(char *l, t_pRead *s, t_data *d)
{
	if (((!*l || *l == 'L') && !s->step) ||
		((!ft_strcmp(l, "##start") && s->start)) ||
		(!ft_strcmp(l, "##end") && s->end))
		pAsciiMsg(l, 1);
	else if (l[0] != '#')
	{
		if ((!(s->j = pType(l)) && !s->step) || (s->j == 2 && !d->box))
			pAsciiMsg(l, 1);
		else if (s->j == 1 && !s->step)
			;
		else if (((s->j == 1 || !s->j) && s->step == 1) ||
				((s->j == 2 && dLink(d, l, -1, -1)) ||
				(s->step && (!*l || *l == 'L'))))
			pAsciiMsg(l, 3);
		else if (s->j == 2)
			pAsciiMsg(l, 7);
	}
	else if (!ft_strcmp(l, "##start") || !ft_strcmp(l, "##end") ||
		!ft_strcmp(l, "##stop"))
		pAsciiMsg(l, 4);
	else if (l[0] && l[0] == '#' && l[1] && l[1] == '#')
	 	pAsciiMsg(l, 3);
	else if (l[0] && l[0] == '#')
		pAsciiMsg(l, 5);
}

void	oData(t_data *d)
{
	ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 " 🐛  Fourmis: ", d->ants);
	ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 " 🗃  Box: ", d->idbox);
	ft_printf("\e[93m  | \e[39m%-40s%35s\e[93m  |\e[39m\n",
	 " 🏁  Start: ", ((d->start) ? d->start->name : "unknow"));
	ft_printf("\e[93m  | \e[39m%-40s%35s\e[93m  |\e[39m\n",
	 " 🏠  End: ", ((d->end) ? d->end->name : "unknow"));
	ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 " 🛤  Chemins valide: ", d->nbroads);
	pAsciiClose();
	pAsciiOpen();
}
