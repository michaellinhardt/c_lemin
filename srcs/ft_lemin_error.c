/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:09:44 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/05 06:40:17 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		eExit(int error)
{
	get_next_line(-10, NULL);
	if (error == 1 && ft_printf("ERROR"))
		exit(0);
	return (1);
}

int		eExit2(int error, char *del)
{
	get_next_line(-10, NULL);
	ft_strdel(&del);
	if (error == 1 && ft_printf("ERROR"))
		exit(0);
	return (1);
}
