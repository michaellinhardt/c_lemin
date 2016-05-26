/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:50:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/26 23:52:23 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "libft.h"
# include "ft_lemin_struct.h"
# include <limits.h>
# include <fcntl.h>

int			eExit(int error, t_data *d, char *msg);
int			eExit2(int error, t_data *d, char *del, char *msg);

char		pType(char *l);
void		pRun(t_data *d);

void		dBox(t_data *d, char *l, int x, char type);
int			dLink(t_data *d, char *l, int i, int j);

void		rRoads(t_data *d, t_pBox *box, char *used, int i);
int			iRoads(t_data *d, t_roads *new, t_pBox **tab, char *u);

void		fDataBox(t_data *d);
void		fRoadsLast(t_data *d);

void		pAscii(void);
int			pAsciiMsg(char *msg, int color);
void		pAsciiClose(void);
void		pAsciiOpen(void);

int			oAnts(char *line);
void		oData(t_data *d);
void		oMap(char *l, t_pRead *s, t_data *d);

int			iCouples(t_data *d);

#endif
