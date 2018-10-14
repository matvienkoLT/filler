/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:09:50 by lmatvien          #+#    #+#             */
/*   Updated: 2018/08/23 16:41:44 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tw_header.h"
#include <stdio.h>

static void			tw_initialization(t_screen *scr)
{
	scr->tw = 0;
	scr->th = 0;
	scr->player0 = NULL;
	scr->player1 = NULL;
	scr->lst = NULL;
	scr->rows = -1;
	scr->width = 0;
	scr->button = 0;
	scr->score_x = 0;
	scr->score_o = 0;
	scr->winner = NULL;
}

static SDL_Texture	*tw_text_init(t_screen *scr)
{
	TTF_Font	*font;
	SDL_Color	textcolor;
	SDL_Texture	*texture;

	font = TTF_OpenFont("kamikaze.3d-gradient-italic.ttf", 70);
	textcolor.r = 76;
	textcolor.g = 206;
	textcolor.b = 176;
	scr->surface = TTF_RenderText_Solid(font, "BATTLEFIELD", textcolor);
	texture = SDL_CreateTextureFromSurface(scr->render, scr->surface);
	SDL_QueryTexture(texture, NULL, NULL, &(scr->tw), &(scr->th));
	scr->dst.x = 75 + SCREEN_W / 4;
	scr->dst.y = 10;
	scr->dst.h = scr->th;
	scr->dst.w = scr->tw;
	TTF_CloseFont(font);
	return (texture);
}

static int			tw_exit(t_screen *scr)
{
	while (SDL_PollEvent(&(scr->ev)))
	{
		if (scr->ev.type == SDL_QUIT)
			return (1);
		if (scr->ev.type == SDL_KEYDOWN)
		{
			if (scr->ev.key.keysym.sym == SDLK_ESCAPE)
				return (1);
			if (scr->ev.key.keysym.sym == SDLK_SPACE && !scr->button)
				scr->button = 1;
			else if (scr->ev.key.keysym.sym == SDLK_SPACE && scr->button)
				scr->button = 0;
			if (scr->ev.key.keysym.sym == SDLK_LEFT && scr->lst->behind)
			{
				scr->button = 0;
				scr->lst = scr->lst->behind;
			}
			if (scr->ev.key.keysym.sym == SDLK_RIGHT && scr->lst->next->map[0])
				scr->lst = scr->lst->next;
		}
	}
	render_element(scr);
	return (0);
}

static int			tw_event(SDL_Window *win)
{
	t_screen	scr;
	int			quit_s;

	quit_s = 0;
	tw_initialization(&scr);
	scr.render = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC |
	SDL_RENDERER_ACCELERATED);
	if (scr.render == NULL)
	{
		ft_putstr_error("Create window error\n");
		SDL_Log("%s", SDL_GetError());
		return (EXIT_FAILURE);
	}
	scr.texture = tw_text_init(&scr);
	scr.name_players0 = render_players_name(&scr);
	tw_maps_list(&scr);
	scr.c_lst = scr.lst;
	scr.kof = tw_kof_size(scr.lst->map[0], scr.rows, &(scr.width));
	scr.score_players0 = render_score(&scr);
	while (!quit_s)
		quit_s = tw_exit(&scr);
	tw_mem_cleaner(&scr);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (EXIT_SUCCESS);
}

int					main(void)
{
	SDL_Window	*win;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr_error("Could not initialize SDL\n");
		SDL_Log("%s", SDL_GetError());
		return (EXIT_FAILURE);
	}
	TTF_Init();
	win = SDL_CreateWindow("Theater of war", 100, 100, SCREEN_W,
	SCREEN_H, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		ft_putstr_error("Create window error\n");
		SDL_Log("%s", SDL_GetError());
		return (EXIT_FAILURE);
	}
	return (tw_event(win));
}
