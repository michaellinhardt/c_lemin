/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_ascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 00:28:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/26 04:00:55 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	pAsciiColor(void)
{
	ft_putstr("\e[93m");
}

void	pAsciiOpen(void)
{
	pAsciiColor();
	ft_printf("                                      |\n");
	ft_printf("  ,-----------------------------------------------------------");
	ft_printf("----------------.\e[39m\n");
}

void	pAsciiClose(void)
{
	pAsciiColor();
	ft_printf("  `-----------------------------------------------------------");
	ft_printf("----------------'\e[39m\n");
}

void	pAscii(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("./incs/ascii", O_RDONLY);
	pAsciiColor();
	while (ft_strdel(&line) && (get_next_line(fd, &line)) > 0)
		ft_printf("%-80s\n", line);
}
