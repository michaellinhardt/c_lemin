/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 15:12:18 by mlinhard         ###   ########.fr       */
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
	int					id;
	char				type;
	int					ant;
	int					size;
	int					sizeok;
	int					x;
	int					y;
	struct s_pBox		*n;
	struct s_pBoxLink	*links;
}						t_pBox;

typedef struct			s_roads
{
	int					id;
	int					score;
	char				*u;
	t_pBox				**tab;
	struct s_roads		*n;
}						t_roads;

typedef struct			s_couple
{
	int					score;
	struct s_roads		*r;
	struct s_couple		*n;
	struct s_couple		*p;
}						t_couple;

typedef struct			t_pRead
{
	int					i;
	char				j;
	char				type;
	char				start;
	char				end;
	char				step;
}						t_pRead;

typedef struct			s_data
{
	int					i;
	char				ret;
	int					idbox;
	int					ants;
	int					rendmax;
	int					tmax;
	int					nbroads;
	int					roadsmax;
	t_couple			*p;
	t_couple			*solution;
	t_couple			*couples;
	char				*name;
	t_roads				*roads;
	t_pBox				*box;
	t_pBox				*start;
	t_pBox				*end;
}						t_data;

#endif
