/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 02:14:44 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 16:53:59 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int			oants(char *line)
{
	size_t		len;
	char		*verif;

	len = 0;
	verif = line;
	while (line && *verif && ft_isdigit(*verif))
		verif++;
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		pasciimsg(line, 1);
	else if (*line == '#')
		pasciimsg(line, 5);
	else if (!line)
		pasciimsg("(get_next_line return NULL for line)", 5);
	else if ((len = ft_strlen(line)) > 10)
		pasciimsg(line, 1);
	else if (len == 10 && ft_atoimax(line) > INT_MAX)
		pasciimsg(line, 1);
	else if (line && (!*verif))
		pasciimsg(line, 6);
	else
		pasciimsg(line, 1);
	return (0);
}

void		omap(char *l, t_pride *s, t_data *d)
{
	if (((!*l || *l == 'L') && !s->step) ||
		((!ft_strcmp(l, "##start") && s->start)) ||
		(!ft_strcmp(l, "##end") && s->end))
		pasciimsg(l, 1);
	else if (l[0] != '#')
	{
		if ((!(s->j = ptype(l)) && !s->step) || (s->j == 2 && !d->box))
			pasciimsg(l, 1);
		else if (s->j == 1 && !s->step)
			;
		else if (((s->j == 1 || !s->j) && s->step == 1) ||
				((s->j == 2 && dlink(d, l, -1, -1)) ||
				(s->step && (!*l || *l == 'L'))))
			pasciimsg(l, 3);
		else if (s->j == 2)
			pasciimsg(l, 7);
	}
	else if (!ft_strcmp(l, "##start") || !ft_strcmp(l, "##end") ||
		!ft_strcmp(l, "##stop"))
		pasciimsg(l, 4);
	else if (l[0] && l[0] == '#' && l[1] && l[1] == '#')
	 	pasciimsg(l, 3);
	else if (l[0] && l[0] == '#')
		pasciimsg(l, 5);
}

void		odata(t_data *d)
{
	ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 " 🐛  Fourmis: ", d->ants);
	ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 " 🗃  Box: ", d->idbox);
	ft_printf("\e[93m  | \e[39m%-40s%35s\e[93m  |\e[39m\n",
	 " 🏁  Start: ", ((d->start) ? d->start->name : "unknow"));
	ft_printf("\e[93m  | \e[39m%-40s%35s\e[93m  |\e[39m\n",
	 " 🏠  End: ", ((d->end) ? d->end->name : "unknow"));
	 if (d->idbox <= 100)
	{
		ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 	" 🛤  Chemins valide: ", d->nbroads);
		ft_printf("\e[93m  | \e[39m%-70s%5d\e[93m  |\e[39m\n",
	 	" 🛤  Chemins utilisables: ", d->roadsmax);
	}
	pasciiclose();
	pasciiopen(0);
}

void		printcouples(t_couple *lst)
{
	t_roads *road;
	int i;

	while (lst)
	{
		ft_printf("%5s", " ");
		if (lst->r)
		{
			ft_printf("🛤  Road %3d: ", lst->r->id);
			road = lst->r;
			i = -1;
			while (road->tab[++i])
				ft_printf("[%s] ", road->tab[i]->name);
			ft_printf("\n");
		}
		lst = lst->n;
	}
}
