/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tw_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:13:11 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/23 16:42:26 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tw_header.h"

#define F_REND TTF_RenderText_Solid
#define CTFS   SDL_CreateTextureFromSurface
#define FONT   scr->font_score

static int			tw_players_name(t_screen *src)
{
	int		name_catch;
	char	*temp;
	char	*name_temp;

	name_catch = 0;
	while (name_catch != 2 && get_next_line(0, &temp))
	{
		if (ft_strstr(temp, "launched"))
		{
			if ((name_temp = ft_strrchr(temp, '/')) != NULL)
			{
				if (!src->player0)
					src->player0 = ft_strdup(name_temp + 1);
				else
					src->player1 = ft_strdup(name_temp + 1);
				name_catch++;
			}
		}
		free(temp);
	}
	return (1);
}

void				render_winner(t_screen *scr, char *name, char *result)
{
	SDL_Color	textcolor;
	char		*tt;

	textcolor.r = 76;
	textcolor.g = 206;
	textcolor.b = 176;
	SDL_FreeSurface(scr->surface);
	tt = ft_strjoin(result, name);
	scr->surface = F_REND(scr->font_score, tt, textcolor);
	free(tt);
	scr->winner = CTFS(scr->render, scr->surface);
	SDL_QueryTexture(scr->winner, NULL, NULL, &(scr->tw), &(scr->th));
	scr->name.x = 350;
	scr->name.y = 920;
	scr->name.h = scr->th;
	scr->name.w = scr->tw;
}

SDL_Texture			*render_score(t_screen *scr)
{
	SDL_Color	textcolor;
	SDL_Texture	*texture;
	char		*tt;

	scr->font_score = TTF_OpenFont("Danger.ttf", 90);
	textcolor.r = 0xFF;
	textcolor.g = 0xFF;
	textcolor.b = 0xFF;
	tt = ft_itoa(scr->lst->score_o);
	SDL_FreeSurface(scr->surface);
	scr->surface = F_REND(FONT, tt, textcolor);
	texture = CTFS(scr->render, scr->surface);
	SDL_QueryTexture(texture, NULL, NULL, &(scr->tw), &(scr->th));
	scr->s_o.x = 55;
	scr->s_o.y = 900;
	scr->s_x.x = SCREEN_W - 140;
	scr->s_x.y = 900;
	scr->s_o.h = scr->th;
	scr->s_o.w = scr->tw;
	free(tt);
	return (texture);
}

static	SDL_Texture	*render_players_name2(t_screen *scr, TTF_Font *font)
{
	SDL_Texture *texture;
	SDL_Color	textcolor;

	textcolor.r = 0xFF;
	SDL_FreeSurface(scr->surface);
	scr->surface = TTF_RenderText_Solid(font, scr->player1, textcolor);
	texture = SDL_CreateTextureFromSurface(scr->render, scr->surface);
	SDL_QueryTexture(texture, NULL, NULL, &(scr->tw), &(scr->th));
	scr->name1.x = 925;
	scr->name1.y = 75;
	scr->name1.h = scr->th;
	scr->name1.w = scr->tw;
	TTF_CloseFont(font);
	return (texture);
}

SDL_Texture			*render_players_name(t_screen *scr)
{
	TTF_Font	*font;
	SDL_Color	textcolor;
	SDL_Texture	*texture;

	font = TTF_OpenFont("Danger.ttf", 60);
	textcolor.r = 0xFF;
	textcolor.g = 0xFF;
	textcolor.b = 0xFF;
	tw_players_name(scr);
	SDL_FreeSurface(scr->surface);
	scr->surface = TTF_RenderText_Solid(font, scr->player0, textcolor);
	texture = SDL_CreateTextureFromSurface(scr->render, scr->surface);
	SDL_QueryTexture(texture, NULL, NULL, &(scr->tw), &(scr->th));
	scr->name0.x = 175;
	scr->name0.y = 75;
	scr->name0.h = scr->th;
	scr->name0.w = scr->tw;
	scr->name_players1 = render_players_name2(scr, font);
	return (texture);
}
