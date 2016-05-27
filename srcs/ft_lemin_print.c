/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:08:28 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 16:58:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"



int			dPrint(t_data *d, t_couple *sol, t_couple *new, t_couple *prev)
{
	if (!d->p && (d->p = new))
		return (0);
	if (d->p->r->score > new->r->score && (new->n = d->p))
	{
		d->p->p = new;
		d->p = new;
		return (1);
	}
	if (!d->p->n && d->p->r->score < new->r->score && (d->p->n = new))
	{
		new->p = d->p;
		return (1);
	}
	while (sol->n && sol->r->score < new->r->score && ((prev = sol) || 1))
		sol = sol->n;
	if (!sol->n && (sol->n = new))
		new->p = sol;
	else if (prev && (new->n = sol))
	{
		sol->p = new;
		new->p = prev;
		prev->n = new;
	}
	return (0);
}

void		iPrint(t_data *d, t_couple *sol, t_couple *new)
{
	while (sol && sol->r)
	{
		if (!(new = (t_couple *)ft_memalloc(sizeof(t_couple))))
			eExit(1, d, "Cant malloc.");
		new->r = sol->r;
		new->n = NULL;
		new->p = NULL;
		new->score = sol->score;
		dPrint(d, d->p, new, (t_couple *)NULL);
		sol = sol->n;
	}
}

void		oPrintMove(t_data *d, t_pBox **tab, int type, int f)
{
	if (type == 1)
	{
		ft_printf("L%d-%s ", tab[d->i]->ant, tab[(d->i + 1)]->name);
		tab[(d->i + 1)]->ant = tab[d->i]->ant;
		tab[d->i]->ant = 0;
		if (tab[(d->i + 1)]->type == 2)
			d->ret++;
	}
	else if (type == 2)
	{
		tab[1]->ant = f;
		ft_printf("L%d-%s ", f, tab[1]->name);
		if (tab[1]->type == 2)
			d->ret++;
	}
}

void		oPrint(t_data *d, t_couple *cpl, t_roads *rds, int f)
{
	iPrint(d, d->solution, d->solution);
	printCouples(d->p);
	pAsciiOpen(0);
	pAsciiMsg("Résultat:", 8);
	pAsciiClose();
	while (d->ret < d->tmax && ++d->rendmax)
	{
		ft_printf("%5s%s", " ", "🛤  ", d->ret);
		cpl = d->p;
		while (cpl && cpl->r)
		{
			rds = cpl->r;
			d->i = (rds->score);
			while (--d->i > -1)
				(rds->tab[d->i] && rds->tab[d->i]->ant) ? oPrintMove(d,
					 rds->tab, 1, 0) : 1;
			if (d->ants-- > 0)
				oPrintMove(d, rds->tab, 2, ++f);
			cpl = cpl->n;
		}
		ft_printf("\n");
	}
	pAsciiOpen(0);
	ft_printf("\e[93m  | \e[39m%-40s%35d\e[93m  |\e[39m\n",
	 " 🏁  Nombre de tour: ", d->rendmax);
	pAsciiClose();
}
