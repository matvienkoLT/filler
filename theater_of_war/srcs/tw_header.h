/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tw_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:33:17 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/22 13:23:38 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TW_HEADER_H
# define TW_HEADER_H

# include "SDL.h"
# include "../../srcs/libft_mini/libft.h"
# include "SDL_ttf.h"

# define SCREEN_W	1280
# define SCREEN_H	1024

typedef struct		s_lmap
{
	struct s_lmap	*next;
	struct s_lmap	*behind;
	char			**map;
	int				score_o;
	int				score_x;

}					t_lmap;

typedef struct		s_screen
{
	t_lmap			*lst;
	t_lmap			*c_lst;
	int				rows;
	int				width;
	int				kof;
	int				button;
	int				score_x;
	int				score_o;
	SDL_Renderer	*render;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Texture		*name_players0;
	SDL_Texture		*name_players1;
	SDL_Texture		*score_players0;
	SDL_Texture		*score_players1;
	SDL_Texture		*winner;
	SDL_Event		ev;
	SDL_Rect		dst;
	SDL_Rect		name0;
	SDL_Rect		name1;
	SDL_Rect		s_x;
	SDL_Rect		s_o;
	SDL_Rect		name;
	TTF_Font		*font_score;
	int				tw;
	int				th;
	char			*player0;
	char			*player1;
}					t_screen;

SDL_Texture			*render_players_name(t_screen *scr);
SDL_Texture			*render_score(t_screen *scr);
void				tw_maps_list(t_screen *scr);
void				tw_grid_draw(t_screen *scr);
void				render_winner(t_screen *scr, char *name, char *result);
t_lmap				*tw_create_element(t_lmap *element, int size);
int					tw_kof_size(char *str, int m_rows, int *m_width);
void				render_element(t_screen *scr);
void				tw_mem_cleaner(t_screen *scr);

#endif
