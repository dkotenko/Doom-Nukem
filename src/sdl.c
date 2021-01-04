/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:32:04 by clala             #+#    #+#             */
/*   Updated: 2020/10/24 21:38:14 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
static void		handle_other_keys(t_render *render)
{
	if (render->sdl->state[SDL_SCANCODE_I])
		render->bon->fps = render->bon->fps == 0 ? 1 : 0;
	if (render->sdl->state[SDL_SCANCODE_H])
		render->sdl->menu = render->sdl->menu ? 0 : 1;
}
*/
static void		handle_keys(t_render *render, SDL_Event *event)
{
	const		Uint8 *s;

	s = render->sdl->state;
	if (event->key.keysym.sym == SDLK_ESCAPE)
		render->sdl->run = false;
	
	if (s[SDL_SCANCODE_D])
		render->camera->position = t_vec4_add(render->camera->position, t_vec4_muln(render->camera->right, render->camera->moving_speed));
	if (s[SDL_SCANCODE_A])
		render->camera->position = t_vec4_sub(render->camera->position, t_vec4_muln(render->camera->right, render->camera->moving_speed));
	if (s[SDL_SCANCODE_W])
		render->camera->position = t_vec4_add(render->camera->position, t_vec4_muln(render->camera->forward, render->camera->moving_speed));
	if (s[SDL_SCANCODE_S])
	{
		render->camera->position = t_vec4_sub(render->camera->position, t_vec4_muln(render->camera->forward, render->camera->moving_speed));
	}
	if (s[SDL_SCANCODE_Q])
		render->camera->position = t_vec4_add(render->camera->position, t_vec4_muln(render->camera->up, render->camera->moving_speed));
	if (s[SDL_SCANCODE_E])
		render->camera->position = t_vec4_sub(render->camera->position, t_vec4_muln(render->camera->up, render->camera->moving_speed));
	
	if (s[SDL_SCANCODE_LEFT])
		camera_yaw(render->camera, -render->camera->rotation_speed);
	if (s[SDL_SCANCODE_RIGHT])
		camera_yaw(render->camera, render->camera->rotation_speed);
	if (s[SDL_SCANCODE_UP])
		camera_pitch(render->camera, render->camera->rotation_speed);
	if (s[SDL_SCANCODE_DOWN])
		camera_pitch(render->camera, -render->camera->rotation_speed);
	/*
		calc_move(map, p, p->speed * sinf(p->dir - RAD_90),
		-(p->speed * cosf(p->dir - RAD_90)));
	if (s[SDL_SCANCODE_DOWN] || s[SDL_SCANCODE_S])
		calc_move(map, p, p->speed * sinf(p->dir), -(p->speed * cosf(p->dir)));
	if (s[SDL_SCANCODE_W] || s[SDL_SCANCODE_UP])
		calc_move(map, p, -(p->speed * sinf(p->dir)), p->speed * cosf(p->dir));
	if ((s[SDL_SCANCODE_RIGHT] || s[SDL_SCANCODE_E])
	&& add_arc(&p->dir, -RAD_30))
		add_skybox_offset(render->sdl, 52);
	if ((s[SDL_SCANCODE_LEFT] || s[SDL_SCANCODE_Q]) && add_arc(&p->dir, RAD_30))
		add_skybox_offset(render->sdl, -52);
	if (s[SDL_SCANCODE_P])
		render->sdl->sides_mode = render->sdl->sides_mode == 1 ? 0 : 1;
	if (s[SDL_SCANCODE_M])
		map->mm_show = map->mm_show == 1 ? 0 : 1;
	handle_other_keys(render);
	
*/
}

static void		handle_event(t_render *render, SDL_Event *event)
{
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT)
			render->sdl->run = false;
			/*
		if (event->type == SDL_MOUSEMOTION)
			rotate(render, event, x);
			*/
		if (event->type == SDL_KEYDOWN)
			handle_keys(render, event);
	}
}


void			render_loop(t_render *render)
{
	SDL_Event	event;
	int			x;

	init_sdl(render);
	x = -0x7fffff;
	while (render->sdl->run)
	{
		//print_t_polygon(render->object->sector->polygons[0]);	
		handle_event(render, &event); //, &x);
		draw_background(render->surface);
		
		screen_projection(render, render->object);
		draw_polygons(render);
		//all_get_distance(render);
		//pseudo_3d(render, render->player, render->surface);
		render_fps(render, render->bon);
		//render->map->mm_show ? draw_minimap(render, render->map, render->player) : 0;
		//render->sdl->menu ? draw_menu(render) : 0;
		SDL_UpdateWindowSurface(render->sdl->win);
	}
	SDL_DestroyWindow(render->sdl->win);
	TTF_Quit();
	SDL_Quit();
	exit(EXIT_SUCCESS);
}
