/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:50:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 18:18:17 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "libft.h"
# include "ft_lemin_struct.h"
# include <limits.h>
# include <fcntl.h>

int			eexit(int error, t_data *d, char *msg);
int			eexit2(int error, t_data *d, char *del, char *msg);

char		ptype(char *l);
void		prun(t_data *d);

void		dbox(t_data *d, char *l, int x, char type);
int			dlink(t_data *d, char *l, int i, int j);

void		rroads(t_data *d, t_pbox *box, char *used, int i);
int			iroads(t_data *d, t_roads *new, t_pbox **tab, char *u);

void		fdatabox(t_data *d);
void		froadslast(t_data *d);

void		printcouples(t_couple *lst);
void		pascii(void);
int			pasciimsg(char *msg, int color);
void		pasciiclose(void);
void		pasciiopen(int i);

int			oants(char *line);
void		odata(t_data *d);
void		omap(char *l, t_pride *s, t_data *d);

void		icouplesstruct(t_data *d, t_couple *new, int i, t_couple **ptr);
int			icouples(t_data *d);

void		rcouples(t_data *d, int slot, t_couple *lst);

void		rsize(t_data *d, int s, t_pboxlink *lnk, t_pboxlink *root);
void		isizeroad(t_data *d, t_pbox *next, t_pboxlink *lnk, t_roads *road);

void		oprint(t_data *d, t_couple *cpl, t_roads *rds, int f);

#endif
