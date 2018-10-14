/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_mforces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:46:46 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/23 16:30:56 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_header.h"

#define I PNT->i_f
#define J PNT->j_f
#define MAP b->map
#define FIG b->fig
#define PNT b->point
#define M_I b->point->i
#define M_J b->point->j
#define X b->point->x
#define Y b->point->y
#define X1 p->x
#define Y1 p->y

static void	way_init(t_info *b, int way, int pre_serve_x, int pre_serve_y)
{
	if (PNT->way >= way)
	{
		PNT->way = way;
		X = pre_serve_x;
		Y = pre_serve_y;
	}
}

void		cmp_points(t_info *b, int i, int j)
{
	t_cord	*p;
	int		way;
	int		p_s[2];

	p = b->enemy_w;
	p_s[0] = M_J - J;
	p_s[1] = M_I - I;
	while (p)
	{
		while (i < b->f_rows && (FIG[i][j] != '\n' || FIG[i][j] != '\0'))
		{
			if (FIG[i][j] == '*')
			{
				way = FT_ABS((p_s[0] + j) - X1) + FT_ABS((p_s[1] + i) - Y1);
				way_init(b, way, p_s[0], p_s[1]);
			}
			j++;
			if (j >= b->f_width)
			{
				j = 0;
				i++;
			}
		}
		p = p->next;
	}
}

int			clear_way_mforces(t_info *b)
{
	char	**fig;
	int		status;

	status = 0;
	I = 0;
	J = 0;
	fig = b->fig;
	while (I < b->f_rows && fig[I][J] != '\0')
	{
		if (fig[I][J] == '*')
		{
			if (ck_fig_v_r(b, 1))
			{
				status = 1;
				cmp_points(b, 0, 0);
			}
		}
		J++;
		if (J >= b->f_width)
		{
			I++;
			J = 0;
		}
	}
	return (status);
}

void		fl_mforces(t_info *lst, char c)
{
	char	**box;

	box = lst->map;
	lst->point->i = 0;
	lst->point->j = 0;
	while (box[lst->point->i])
	{
		if (box[lst->point->i][lst->point->j] == c)
		{
			lst->point->c = c;
			clear_way_mforces(lst);
		}
		else if (box[lst->point->i][lst->point->j] == '\0')
		{
			lst->point->i++;
			lst->point->j = 0;
			continue;
		}
		lst->point->j++;
	}
}
