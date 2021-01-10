/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:31:45 by clala             #+#    #+#             */
/*   Updated: 2021/01/05 22:19:52 by majosue          ###   ########.fr       */
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
# include "vec4.h"
# include "vec3.h"
# include "matrix4.h"


/*
typedef struct	s_polygon
{
	t_vec2		v1;
	t_vec2		v2;
	float		height;
	float		width;
	int			texture;
}			t_polygon;
*/

typedef struct	s_vertex
{
	t_vector4d	vertex_origin;
	t_vector4d	vertex;
	int			to_draw;
}				t_vertex;

typedef struct	s_polygon
{
	t_vertex	**vertices;
	int			curr_size;
	int			max_size;
	int			to_draw;
	int			color;
	int			*vert_to_draw;

	t_vector4d	normal_origin;
	t_vector4d	normal;
	//Texture* texture;
	//Sector* sector;
	//Plane plane;
}				t_polygon;

typedef struct	s_sector
{
	t_polygon** polygons;
	int			curr_size;
	int			max_size;
	float		*centroids_dist;
	int			*z_buf;
	//ObjectList* objects;
}				t_sector;

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

typedef struct	s_bonus
{
	int			fps;
	Uint32		start_time;
	int			fps_count;
	TTF_Font	*my_font;
}				t_bonus;




/*
==========================

*/



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



typedef struct	s_object
{
	t_sector	*sector;
	int			*to_draw;
}				t_object;





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
	float		near;
	float		far;
	float		right;
	float 		left;
	float		top;
	float		bottom;
}				t_projection;

typedef	struct		s_render
{
	float			half_width;
	float			half_height;
	float			width;
	float			height;
	t_camera		*camera;
	t_projection	*projection;
	t_object		*object;
	t_sdl			*sdl;
	SDL_Surface		*surface;
	t_bonus			*bon;
}					t_render;



void		render_loop(t_render *render);
void		init_sdl(t_render *render);
void		print_t_matrix(t_matrix4 *matrix);
t_matrix4	m4_mult(t_matrix4 mat_a, t_matrix4 mat_b);
t_vector4d	vec4_m4_mult(t_vector4d vec4, t_matrix4 m4);
t_matrix4	*t_matrix4_new(float values[M4_SIZE]);
void		t_projection_init(t_render *render);
t_matrix4	*t_matrix4_new(float values[M4_SIZE]);



void	init_bonus(t_render *render);

/*
** camera.c
*/
t_camera		*t_camera_new(t_render *render, t_vector3d position);
t_matrix4	get_camera_matrix(t_camera *camera);
t_matrix4	get_translated_matrix(t_camera *camera);
t_matrix4	get_rotated_matrix(t_camera *camera);
void		camera_yaw(t_camera *camera, float angle);
void		camera_pitch(t_camera *camera, float angle);


/*
** set_sdl.c
*/
SDL_Color	set_color_sdl(int a, int b, int c);
SDL_Rect	set_rect_sdl(int x, int y, int w, int h);

/*
** error.c
*/
int		error(t_render *render, const char *s);
int		error_free_s(t_render *render, char *s);
int		error_inv_c(t_render *render, char *s, char inv_char);
int		error_inv_n(t_render *render, char *s, int inv_num);

/*
** main.c
*/
t_point			dot(int x, int y);
int				max(int a, int b);

/*
** draw.c
*/
void			draw_line(SDL_Surface *surface,
t_point start, t_point end, int color);
void			draw_rectangle(SDL_Surface *surface, t_point start,
t_point width_height, int color);
void			draw_background(SDL_Surface *surface);
void 			draw_circle(SDL_Surface *surface, int xc, int yc, int r) ;

/*
** render_text.c
*/
void			render_text(t_render *render, char *text, SDL_Rect location,
					SDL_Color f_b_color[2]);
void			render_fps(t_render *render, t_bonus *bon);
int				get_fps_time(t_bonus *bon);

/*
** render_texture.c
*/
void			set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
Uint32			get_pixel(SDL_Surface *surface, int x, int y);

/*
** object3d.c
*/
t_object		*t_object_new(t_render *render, t_sector **sector);


void			vertices_map_matrix(t_object *object, t_matrix4 matrix);
void			vertices_rotate_x(t_object *object, float value);
void			vertices_rotate_y(t_object *object, float value);
void			vertices_rotate_z(t_object *object, float value);
void			vertices_rotate_scale(t_object *object, float value);
void			vertices_translate(t_object *object, t_matrix4 matrix);
void			vertices_normalize_and_reshape(t_vertex *vertex);
void			screen_projection(t_render *render, t_object *object);
t_vector3d		t_vec3_new(float x, float y, float z);

void 			here(void);

/*
** matrix_functions.c
*/
t_matrix4		translate(t_vector3d position);
t_matrix4		rotate_x(float angle);
t_matrix4		rotate_y(float angle);
t_matrix4		rotate_z(float angle);
t_matrix4		scale(float n);

/*
** projection.c
*/
void			t_projection_init(t_render *render);

void			print_t_vec4(t_vector4d v);

/*
** t_polygon.c
*/
void			t_polygon_add_vertex(t_polygon *polygon, t_vector4d to_add);
void			t_polygon_add_normal(t_polygon *polygon, t_vector4d to_add);
t_polygon		*t_polygon_new(int vert_number, int color);
t_vector3d		t_polygon_get_centroid(t_polygon *polygon);
void			print_t_polygon(t_polygon *polygon);
/*
** t_sector.c
*/
t_sector		*t_sector_new(int polygons_number);
void			t_sector_add_polygon(t_sector *sector, t_polygon *polygon);

/*
** t_vec4.c
*/



void	draw_polygons(t_render *render);
#endif
