/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:09:44 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/26 06:18:23 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		eExit(int error, t_data *d, char *msg)
{
	if (error == 1)
		;
	pAsciiClose();
	pAsciiOpen();
	oData(d);
	fDataBox(d);
	ft_printf("\e[93m  | \e[31m%s%-62s\e[93m  |\n", "🚨  Error: ", msg);
	pAsciiClose();
	get_next_line(-10, NULL);
	exit(0);
	return (1);
}

int		eExit2(int error, t_data *d, char *del, char *msg)
{
	if (error == 1)
		;
	pAsciiClose();
	pAsciiOpen();
	oData(d);
	ft_strdel(&del);
	fDataBox(d);
	ft_printf("\e[93m  | \e[31m%s%-62s\e[93m  |\n", "🚨  Error: ", msg);
	pAsciiClose();
	get_next_line(-10, NULL);
	exit(0);
	return (1);
}
