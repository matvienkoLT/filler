/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:57:30 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/12 20:34:03 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_HEADER_H
# define FL_HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include "../srcs/libft_mini/libft.h"

# define FT_ABS(x) (((x)<0)?-(x):(x))

typedef struct		s_cord
{
	int				x;
	int				y;
	short int		written;
	struct s_cord	*next;
	struct s_cord	*previous;
}					t_cord;

typedef struct		s_point
{
	int				x;
	int				y;
	int				i_f;
	int				j_f;
	int				i;
	int				j;
	int				way;
	char			c;
}					t_point;

typedef struct		s_info
{
	int				player;
	int				m_width;
	int				m_rows;
	int				f_width;
	int				f_rows;
	char			**fig;
	char			**map;
	t_cord			*enemy_w;
	t_point			*point;
}					t_info;
int					fl_reader(int fd, t_info *gr);
void				fl_writer(t_info *gl, int fd);
t_cord				*enemy_tops(t_info *lst, char c);
void				fl_map_size(char *str, t_info *gr);
void				fl_mforces(t_info *lst, char c);
int					clear_way_enemy(t_info *b, int i, int j);
int					fig_clear_case(t_info *b, char c);
t_cord				*find_elem(t_cord *block, int *i, int *j, t_info *lst);
int					ck_fig_v_r(t_info *b, int n);
t_cord				*create_lst(t_info *lst);
void				fl_tops(t_info *box);
#endif
