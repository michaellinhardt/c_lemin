/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/05 05:15:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_STRUCT_H
# define FT_LEMIN_STRUCT_H

typedef struct			s_pBox
{
	char				*name;
	int					x;
	int					y;
	struct s_pBox		*n;
}						t_pBox;

typedef struct			s_data
{
	int					ants;
	t_pBox				*box;
}						t_data;

#endif
