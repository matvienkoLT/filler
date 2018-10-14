/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tw_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 09:42:23 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/23 16:38:52 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tw_header.h"

#define K      SCREEN_W / 2 - (scr->width / 2 * scr->kof)
#define FONT   scr->font_score
#define F_REND TTF_RenderText_Solid
#define CTFS   SDL_CreateTextureFromSurface

int			tw_kof_size(char *str, int m_rows, int *m_width)
{
	while (*str != '\n' && *str != '\0')
	{
		(*m_width)++;
		str++;
	}
	if (m_rows <= 20 && *m_width <= 30)
		return (30);
	else if (m_rows <= 50 && *m_width <= 60)
		return (20);
	else if (m_rows > 110 && *m_width > 120)
		return (4);
	else
		return (8);
}

static void	tw_render_rect(t_screen *scr, SDL_Rect *box, char *map)
{
	if (*map == 'X')
	{
		SDL_SetRenderDrawColor(scr->render, 255, 0, 0, 0);
		SDL_RenderFillRect(scr->render, box);
	}
	if (*map == 'O')
	{
		SDL_SetRenderDrawColor(scr->render, 255, 255, 255, 0);
		SDL_RenderFillRect(scr->render, box);
	}
	if (*map == 'o')
	{
		SDL_SetRenderDrawColor(scr->render, 0, 191, 255, 0);
		SDL_RenderFillRect(scr->render, box);
	}
	if (*map == 'x')
	{
		SDL_SetRenderDrawColor(scr->render, 246, 123, 0, 0);
		SDL_RenderFillRect(scr->render, box);
	}
}

static void	color_initialization(SDL_Color *textcolor, SDL_Color *textcolor2)
{
	textcolor->r = 255;
	textcolor->b = 255;
	textcolor->g = 255;
	textcolor2->r = 255;
	textcolor2->b = 0;
	textcolor2->g = 0;
}

static void	tw_score_render(t_screen *scr)
{
	SDL_Color	textcolor;
	SDL_Color	textcolor2;
	char		*tt;

	color_initialization(&textcolor, &textcolor2);
	SDL_FreeSurface(scr->surface);
	tt = ft_itoa(scr->lst->score_o);
	scr->surface = F_REND(FONT, tt, textcolor);
	free(tt);
	scr->score_players0 = CTFS(scr->render, scr->surface);
	SDL_QueryTexture(scr->score_players0, NULL, NULL, &(scr->tw), &(scr->th));
	scr->s_o.h = scr->th;
	scr->s_o.w = scr->tw;
	SDL_FreeSurface(scr->surface);
	tt = ft_itoa(scr->lst->score_x);
	scr->surface = F_REND(FONT, tt, textcolor2);
	free(tt);
	scr->score_players1 = CTFS(scr->render, scr->surface);
	SDL_QueryTexture(scr->score_players1, NULL, NULL, &(scr->tw), &(scr->th));
	scr->s_x.h = scr->th;
	scr->s_x.w = scr->tw;
}

void		tw_grid_draw(t_screen *scr)
{
	SDL_Rect	box;
	char		**map;
	int			i[2];

	i[0] = 0;
	i[1] = 0;
	box.w = scr->kof;
	box.h = scr->kof;
	map = scr->lst->map;
	tw_score_render(scr);
	while (map[i[0]])
	{
		while (map[i[0]][i[1]] != '\0' && map[i[0]][i[1]] != '\n')
		{
			box.x = K + i[1] * scr->kof;
			box.y = 150 + i[0] * scr->kof;
			tw_render_rect(scr, &box, &map[i[0]][i[1]]);
			SDL_SetRenderDrawColor(scr->render, 76, 206, 176, 0);
			SDL_RenderDrawRect(scr->render, &box);
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
}
