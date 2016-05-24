/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:25:02 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/24 11:29:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	sSize(t_data *d, t_pBox *start, t_pBox *end)
{
	(void)d;
	ft_printf("start: %s -> %s\n", start->name, end->name);
}
