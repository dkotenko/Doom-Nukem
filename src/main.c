/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:29:09 by clala             #+#    #+#             */
/*   Updated: 2021/01/10 12:35:58 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_point			dot(int x, int y)
{
	t_point	new;

	new.x = x;
	new.y = y;
	return (new);
}

int				max(int a, int b)
{
	return (a > b ? a : b);
}


t_render	*t_render_new(void)
{
	t_render		*new;

	!(new = (t_render *)malloc(sizeof(t_render))) ? error(new, ERR_MALLOC) : 0;

	if (!(new->sdl = (t_sdl *)malloc(sizeof(t_sdl))))
		error(new, ERR_MALLOC);
	if (!(new->bon = (t_bonus *)malloc(sizeof(t_bonus))))
		error(new, ERR_MALLOC);
	new->height = H;
	new->width = W;
	new->half_height = H / 2;
	new->half_width = W / 2;
	return (new);
}




/*
void		validate_const(t_wolf *wolf)
{
	H > W ? error(wolf, ERR_INV_H) : 0;
	H < 300 || W < 384 ? error(wolf, ERR_INV_RES) : 0;
	H > H_MAX ? error_inv_n(wolf, ERR_H_MAX, H_MAX) : 0;
	W > W_MAX ? error_inv_n(wolf, ERR_W_MAX, W_MAX) : 0;
}
*/

/*
** No array overflow handling
*/





void here()
{
	ft_printf("here\n");
}

int				main(void)
{
	t_render *render;
	//t_matrix4 a;
	//t_matrix4 b;
	render = NULL;
	SDL_Init(SDL_INIT_EVERYTHING) != 0 ? error(render, SDL_GetError()) : 0;
	TTF_Init() != 0 ? error(render, SDL_GetError()) : 0;

	t_sector *sector = t_sector_new(6);
	t_polygon *side1 = t_polygon_new(4, COLOR_SKY_BLUE);
	t_polygon *side2 = t_polygon_new(4, 0xFF0000);
	t_polygon *side3 = t_polygon_new(4, COLOR_GREY);
	t_polygon *side4 = t_polygon_new(4, COLOR_GREY_LIGHT);
	t_polygon *side5 = t_polygon_new(4, 0x00FF00);
	t_polygon *side6 = t_polygon_new(4, 0xFFFF00);

	t_sector_add_polygon(sector, side1);
	t_sector_add_polygon(sector, side2);
	t_sector_add_polygon(sector, side3);
	t_sector_add_polygon(sector, side4);
	t_sector_add_polygon(sector, side5);
	t_sector_add_polygon(sector, side6);

	t_vector4d v1 = t_vec4_new(-0.5f, -0.5f, -0.5f, 1.f);
	t_vector4d v2 = t_vec4_new(-0.5f, 0.5f, -0.5f, 1.f);
	t_vector4d v3 = t_vec4_new(0.5f, 0.5f, -0.5f, 1.f);
	t_vector4d v4 = t_vec4_new(0.5f, -0.5f, -0.5f, 1.f);
	t_vector4d v5 = t_vec4_new(-0.5f, -0.5f, 0.5f, 1.f);
	t_vector4d v6 = t_vec4_new(-0.5f, 0.5f, 0.5f, 1.f);
	t_vector4d v7 = t_vec4_new(0.5f, 0.5f, 0.5f, 1.f);
	t_vector4d v8 = t_vec4_new(0.5f, -0.5f, 0.5f, 1.f);

	t_polygon_add_vertex(side1, v1);
	t_polygon_add_vertex(side1, v2);
	t_polygon_add_vertex(side1, v3);
	t_polygon_add_vertex(side1, v4);
	t_polygon_add_normal(side1, (t_vector4d){-0.5, -0.5, -1, 1});

	t_polygon_add_vertex(side2, v1);
	t_polygon_add_vertex(side2, v5);
	t_polygon_add_vertex(side2, v6);
	t_polygon_add_vertex(side2, v2);
	t_polygon_add_normal(side2, (t_vector4d){-1, -0.5, -0.5, 1});

	t_polygon_add_vertex(side3, v5);
	t_polygon_add_vertex(side3, v6);
	t_polygon_add_vertex(side3, v7);
	t_polygon_add_vertex(side3, v8);
	t_polygon_add_normal(side3, (t_vector4d){-0.5, -0.5, 1, 1});

	t_polygon_add_vertex(side4, v3);
	t_polygon_add_vertex(side4, v4);
	t_polygon_add_vertex(side4, v8);
	t_polygon_add_vertex(side4, v7);
	t_polygon_add_normal(side4, (t_vector4d){1, 0.5, -0.5, 1});

	t_polygon_add_vertex(side5, v1);
	t_polygon_add_vertex(side5, v5);
	t_polygon_add_vertex(side5, v8);
	t_polygon_add_vertex(side5, v4);
	t_polygon_add_normal(side5, (t_vector4d){-0.5, -1, -0.5, 1});

	t_polygon_add_vertex(side6, v2);
	t_polygon_add_vertex(side6, v6);
	t_polygon_add_vertex(side6, v7);
	t_polygon_add_vertex(side6, v3);
	t_polygon_add_normal(side6, (t_vector4d){-0.5, 1, -0.5, 1});

	render = t_render_new();
	render->camera = t_camera_new(render, t_vec3_new(-2.5f , 1.5f, -6.f));
	//render->camera = t_camera_new(render, t_vec3_new(0 , 0, -10.f));


	t_projection_init(render);
	render->object = t_object_new(render, &sector);

	init_bonus(render);

	render_loop(render);

	/*
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a.matrix[i * M4_ROWS + j] = 2. * (j + i);
			b.matrix[i * M4_ROWS + j] = 12. * (j + i);
		}
	}
	//print_t_matrix(&b);
	t_vector4d v = (t_vector4d){2,3,4,5};
	//ft_printf("%f %f %f %f", v.x, v.y, v.z, v.w);
	print_t_matrix(&a);
	print_t_matrix(&b);
	a = m4_mult(a,b);
	v = vec4_m4_mult(v, a);
	print_t_matrix(&a);
	*/


}

