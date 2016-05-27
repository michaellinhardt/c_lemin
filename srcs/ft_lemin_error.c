/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:09:44 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 14:31:41 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		eexit(int error, t_data *d, char *msg)
{
	if (error == 1)
		;
	pasciiclose();
	pasciiopen(1);
	odata(d);
	fdatabox(d);
	ft_printf("\e[93m  | \e[31m%s%-62s\e[93m  |\n", "🚨  Error: ", msg);
	pasciiclose();
	get_next_line(-10, NULL);
	exit(0);
	return (1);
}

int		eexit2(int error, t_data *d, char *del, char *msg)
{
	if (error == 1)
		;
	pasciiclose();
	pasciiopen(1);
	odata(d);
	ft_strdel(&del);
	fdatabox(d);
	ft_printf("\e[93m  | \e[31m%s%-62s\e[93m  |\n", "🚨  Error: ", msg);
	pasciiclose();
	get_next_line(-10, NULL);
	exit(0);
	return (1);
}
