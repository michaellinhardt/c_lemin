/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/06 17:31:06 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_STRUCT_H
# define FT_LEMIN_STRUCT_H

typedef struct			s_pBox
{
	char				*name;
	char				type;
	int					x;
	int					y;
	struct s_pBox		*n;
}						t_pBox;

typedef struct			t_pRead
{
	int					i;
	char				type;
	char				start;
	char				end;
	char				step;
}						t_pRead;

typedef struct			s_data
{
	int					ants;
	t_pBox				*box;
}						t_data;

#endif
