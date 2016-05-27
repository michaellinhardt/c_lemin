/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/27 18:17:28 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_STRUCT_H
# define FT_LEMIN_STRUCT_H

typedef struct			s_pboxlink
{
	struct s_pbox		*link;
	struct s_pboxlink	*n;
}						t_pboxlink;

typedef struct			s_pbox
{
	char				*name;
	int					id;
	char				type;
	int					ant;
	int					size;
	int					sizeok;
	int					x;
	int					y;
	struct s_pbox		*n;
	struct s_pboxlink	*links;
}						t_pbox;

typedef struct			s_roads
{
	int					id;
	int					score;
	char				*u;
	t_pbox				**tab;
	struct s_roads		*n;
}						t_roads;

typedef struct			s_couple
{
	int					score;
	struct s_roads		*r;
	struct s_couple		*n;
	struct s_couple		*p;
}						t_couple;

typedef struct			s_pride
{
	int					i;
	char				j;
	char				type;
	char				start;
	char				end;
	char				step;
}						t_pride;

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
	t_pbox				*box;
	t_pbox				*start;
	t_pbox				*end;
}						t_data;

#endif
