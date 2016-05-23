/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:50:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/23 16:29:43 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "libft.h"
# include "ft_lemin_struct.h"
# include <limits.h>

int			eExit(int error, t_data *d);
int			eExit2(int error, t_data *d, char *del);

void		pRun(t_data *d);

void		dBox(t_data *d, char *l, int x, char type);
int			dLink(t_data *d, char *l, int i, int j);

void		fDataBox(t_data *d);

#endif
