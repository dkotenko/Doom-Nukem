/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:31:45 by clala             #+#    #+#             */
/*   Updated: 2020/12/05 20:18:03 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
# include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
# include <stdbool.h>
# include <fcntl.h>
# include "../libft/includes/ft_printf.h"
# include <math.h>
# include "const.h"
# include "colors.h"
# include "errors.h"
# include "vec2.h"
# include "matrix4.h"
# include "vec4.h"

typedef struct	s_polygon
{
	t_vec2		v1;
	t_vec2		v2;
	float		height;
	float		width;
	int			texture;
}			t_polygon;

typedef struct	s_polygons
{
	t_polygon	*polygons_arr;
	int			amount;
}			t_polygons;


typedef struct	s_float2
{
	float		x;
	float		y;
}				t_float2;

typedef struct	s_distance
{
	float		dist;
	char		tex;
	int			offsetx;
	int			side;
	t_float2	coords;
	int			y;
}				t_distance;

typedef struct	s_player
{
	float		x;
	float		y;
	float		speed;
	int			size;
	float		fov;
	float		dir;
	float		dist_to_canvas;
	float		step;
	int			floor_offset;
	t_distance	*distance[W];
	t_distance	*distance_horiz[W];
	t_distance	*distance_vert[W];
}				t_player;

typedef struct	s_bonus
{
	int			music_flag;
	Mix_Music	*music;
	Mix_Chunk	*music_guns;
	Mix_Chunk	*music_coin;
	int			fps;
	Uint32		start_time;
	int			fps_count;
	int			guns_fire;
	SDL_Surface	*image_1;
	SDL_Surface	*image_2;
	SDL_Surface	*image_3;
	SDL_Surface	*image_4;
	SDL_Surface	*image_5;
	SDL_Surface	*image_coin;
	t_float2	coint_pos;
	int			score_coin;
	SDL_Rect	img_location;
	int			flag_guns;
	Uint32		start_guns;
	TTF_Font	*my_font;
}				t_bonus;

typedef struct	s_sdl
{
	SDL_Surface	*scrs;
	SDL_Surface	*textures;
	SDL_Surface	*sky;
	SDL_Surface	*icon;
	SDL_Window	*win;
	int			tex_arr[0xff];
	const Uint8	*state;
	int			skybox_offset;
	int			run;
	int			sides_mode;
	int			menu;
}				t_sdl;


/*
==========================
*/
typedef struct	s_vector3d
{
	float		x;
	float		y;
	float		z;
}				t_vector3d;



typedef	struct s_camera
{
	t_vector4d 	position; // np.array([*position, 1.0])
    t_vector4d 	forward;    	//np.array([0, 0, 1, 1])
    t_vector4d 	up;//np.array([0, 1, 0, 1])
	t_vector4d 	right;//np.array([1, 0, 0, 1])
	float		h_fov; // = math.pi / 3
	float		v_fov; // = h_fov * (render.HEIGHT / render.WIDTH)
	float		near_plane; // = 0.1
	float		far_plane; // = 100
	float		moving_speed; // = 0.3
	float		rotation_speed; // = 0.015
}			t_camera;

typedef struct	s_projection
{
	t_matrix4	projection_matrix;
	t_matrix4	to_screen_matrix;
}				t_projection;

typedef	struct	s_render
{
	int			half_width;
	int			half_height;
	t_camera	*camera;
	t_projection *projection;
}				t_render;

t_matrix4	translate(t_camera *camera);
t_matrix4	rotate_x(float angle);
t_matrix4	rotate_y(float angle);
t_matrix4	rotate_z(float angle);
t_matrix4	scale(float n);
t_matrix4	get_camera_matrix(t_camera *camera);
t_matrix4	get_translated_matrix(t_camera *camera);
t_matrix4	get_rotated_matrix(t_camera *camera);
void		print_t_matrix(t_matrix4 *matrix);
t_matrix4	m4_mult(t_matrix4 mat_a, t_matrix4 mat_b);
t_vector4d	vec4_m4_mult(t_vector4d vec4, t_matrix4 m4);

t_matrix4		*t_matrix4_new(float values[M4_SIZE]);



#endif
