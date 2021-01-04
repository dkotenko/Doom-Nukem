/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:26:06 by clala             #+#    #+#             */
/*   Updated: 2020/10/18 18:26:22 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_sdl(t_render *render)
{
	render->sdl->win = SDL_CreateWindow("render3d", 100,
		100, W, H, SDL_WINDOW_SHOWN);
	!render->sdl->win ? error(render, SDL_GetError()) : 0;
	if (!(render->sdl->icon = SDL_LoadBMP(ICON_PATH)))
		error(render, SDL_GetError());
	SDL_SetWindowIcon(render->sdl->win, render->sdl->icon);
	//SDL_SetWindowIcon(render->sdl->win, render->sdl->icon);
	render->sdl->sides_mode = 1;
	render->surface = SDL_GetWindowSurface(render->sdl->win);
	render->sdl->skybox_offset = 0;
	SDL_SetRelativeMouseMode(SDL_TRUE);
	render->sdl->run = 1;
	render->sdl->menu = 0;
	render->sdl->state = SDL_GetKeyboardState(NULL);
}
