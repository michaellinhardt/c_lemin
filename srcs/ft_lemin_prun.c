/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_prun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:50:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/04 06:26:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

intmax_t	pAnts(char *line, char *verif)
{
	ft_printf("line: %s\n", verif);
	while (*verif++)
	{
		(!ft_isdigit(*verif)) ? ft_printf("nope: %c\n", *verif) : ft_printf("yes: %c\n", *verif);
	}
	ft_printf("line: %s\n", line);
	return (1);
}

void		pRun(t_data *d)
{
	char	*line;

	(get_next_line(0, &line)) ? d->ants = pAnts(line, line) : eExit(1); // nombre de fourmis


	// while (get_next_line(0, &line))
	// 	(ft_printf("%s\n", line) || 1) ? ft_strdel(&line) : 1;
	// ft_strdel(&line);
}
