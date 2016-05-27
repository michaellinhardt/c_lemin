/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_rcouples.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 01:44:06 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 11:37:09 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int			rCouplesCalc(t_data *d, int t, int a, t_couple *lst)
{
	d->couples->score = INT_MAX;
	d->rendmax = 0;
	d->tmax = 0;
	d->ret = 0;
	while (!(d->i = 0) && lst && ++d->rendmax)
	{
		(lst->r && lst->r->score > d->tmax) ? (d->tmax = lst->r->score) : 0;
		lst = (lst->n && lst->n->r) ? lst->n : (t_couple *)NULL;
	}
	while ((a -= d->i) > 0 && ++t && (lst = d->couples))
	{
		if (t > d->solution->score)
			return (0);
		if (t == d->tmax && ((d->ret = (a / d->rendmax)) || 1))
		{
			d->ret += ((a % d->rendmax) > 0) ? t : (t - 1);
			return ((d->couples->score = d->ret));
		}
		while (lst)
		{
			d->i += (lst->r && lst->r->score == t) ? 1 : 0;
			lst = (lst->n && lst->n->r) ? lst->n : (t_couple *)NULL;
		}
	}
	return ((d->couples->score = t));
}

void		rCouplesSave(t_couple *s, t_couple *c, int score, int score2)
{
	t_couple	*s2;
	t_couple	*c2;

	s2 = s;
	c2 = c;
	while (c2)
	{
		score += c2->score;
		score2 += s2->score;
		s2 = s2->n;
		c2 = c2->n;
	}
	if (score > score2)
		return ;
	while (c)
	{
		s->score = c->score;
		s->r = c->r;
		s = s->n;
		c = c->n;
	}
}

int			rCouplesValid(t_data *d, t_couple *cpl, char *u, int i)
{
	u = ft_strnew((d->idbox + 1));
	u = ft_memcpy(u, cpl->r->u, (sizeof(char) * (d->idbox + 1)));
	while ((cpl = cpl->n) && cpl->r)
	{
		i = -1;
		while (++i < (d->idbox + 1))
		{
			if (u[i] == 1 && cpl->r->u[i] == 1 && i != d->start->id &&
				i != d->end->id && ft_strdel(&u))
				return (0);
			else
				u[i] = cpl->r->u[i];
		}
	}
	ft_strdel(&u);
	return (1);
}

void		rCouplesTest(t_data *d, t_couple *lst, t_couple *next)
{
	while (lst && lst->r)
	{
		if (lst->n && lst->n->r && lst->r->id == lst->n->r->id)
			return ;
		if (lst->n && lst->n->r)
			rCouplesTest(d, lst->n, (t_couple *)NULL);
		else if (!(d->i = 0) && rCouplesValid(d, d->couples, (char *)NULL, -1))
		{
			rCouplesCalc(d, 0, d->ants, d->couples);
			if (d->solution->score == 0 ||
				d->solution->score >= d->couples->score)
				rCouplesSave(d->solution, d->couples, 0, 0);
		}
		if (!lst->r->n)
			return ;
		else if ((lst->r = lst->r->n))
		{
			next = lst;
			while (next && next->n && next->n->r && next->r->n)
			{
				next->n->r = next->r->n;
				next = next->n;
			}
		}
	}
}

void		rCouples(t_data *d, int slot, t_couple *lst)
{
	int		slot2;

	while (--slot)
	{
		lst = d->couples;
		slot2 = slot + 1;
		while (lst)
		{
			--slot2;
			if (slot2 < 1)
				lst->r = NULL;
			else if (!lst->p)
				lst->r = d->roads;
			else
				lst->r = (lst->p)->r->n;
			lst = lst->n;
		}
		rCouplesTest(d, d->couples, (t_couple *)NULL);
	}
}
