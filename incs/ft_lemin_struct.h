/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/23 16:57:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_STRUCT_H
# define FT_LEMIN_STRUCT_H

typedef struct			s_pBoxLink
{
	struct s_pBox		*link;
	struct s_pBoxLink	*n;
}						t_pBoxLink;

typedef struct			s_pBox
{
	char				*name;
	char				type;
	int					size;
	int					x;
	int					y;
	struct s_pBox		*n;
	struct s_pBoxLink	*links;
}						t_pBox;

typedef struct			t_pRead
{
	int					i;
	char				j;
	// type permet de déterminer le type de la ligne suivante
	// 1 = start
	// 2 = end
	// 0 = box
	char				type;
	// Si start ou end est à 1 on à déjà enregistré une box début ou fin
	char				start;
	char				end;
	char				step;
}						t_pRead;

typedef struct			s_data
{
	int					i;
	char				ret;
	int					ants;
	t_pBox				*box;
	t_pBox				*start;
	t_pBox				*end;
}						t_data;

#endif
