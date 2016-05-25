/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:09:44 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/25 22:50:40 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		eExit(int error, t_data *d)
{
	get_next_line(-10, NULL);
	fDataBox(d);
	if (error == 1 && ft_printf("ERROR"))
		exit(0);
	return (1);
}

int		eExit2(int error, t_data *d, char *del)
{
	get_next_line(-10, NULL);
	ft_strdel(&del);
	fDataBox(d);
	if (error == 1 && ft_printf("ERROR"))
		exit(0);
	return (1);
}
