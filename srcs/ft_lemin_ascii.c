/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_ascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 00:28:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 16:57:57 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

int		pasciimsg(char *msg, int color)
{
	ft_printf("\e[93m  | ");
	(color == 1) ? ft_putstr("\e[31m 🚨  ") : NULL;
	(color == 2) ? ft_putstr("\e[36m 🗃  ") : NULL;
	(color == 3) ? ft_putstr("\e[90m ⛔  ") : NULL;
	(color == 4) ? ft_putstr("\e[92m ✔  ") : NULL;
	(color == 5) ? ft_putstr("\e[90m 📔  ") : NULL;
	(color == 6) ? ft_putstr("\e[35m 🐛  ") : NULL;
	(color == 7) ? ft_putstr("\e[95m 🛤  ") : NULL;
	(color == 8) ? ft_putstr("\e[36m 🏁  ") : NULL;
	(color == 9) ? ft_putstr("\e[36m 🏠  ") : NULL;
	ft_printf("%-69s\e[93m  |\n", msg);
	return (0);
}

void	pasciicolor(void)
{
	ft_putstr("\e[93m");
}

void	pasciiopen(int i)
{
	pasciicolor();
	if (i != 0)
		ft_printf("                                      |\n");
	ft_printf("  ,-----------------------------------------------------------");
	ft_printf("----------------.\e[39m\n");
}

void	pasciiclose(void)
{
	pasciicolor();
	ft_printf("  `-----------------------------------------------------------");
	ft_printf("----------------'\e[39m\n");
}

void	pascii(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("./incs/ascii", O_RDONLY);
	pasciicolor();
	while (ft_strdel(&line) && (get_next_line(fd, &line)) > 0)
		ft_printf("%-80s\n", line);
}
