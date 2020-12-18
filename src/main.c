/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:29:09 by clala             #+#    #+#             */
/*   Updated: 2020/10/24 21:44:59 by clala            ###   ########.fr       */
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

t_wolf	*t_wolf_new(void)
{
	t_wolf		*new;

	!(new = (t_wolf *)malloc(sizeof(t_wolf))) ? error(new, ERR_MALLOC) : 0;
	!(new->map = (t_map *)malloc(sizeof(t_map))) ? error(new, ERR_MALLOC) : 0;
	if (!(new->player = (t_player *)malloc(sizeof(t_player))))
		error(new, ERR_MALLOC);
	if (!(new->sdl = (t_sdl *)malloc(sizeof(t_sdl))))
		error(new, ERR_MALLOC);
	if (!(new->bon = (t_bonus *)malloc(sizeof(t_bonus))))
		error(new, ERR_MALLOC);
	return (new);
}

void		validate_const(t_wolf *wolf)
{
	H > W ? error(wolf, ERR_INV_H) : 0;
	H < 300 || W < 384 ? error(wolf, ERR_INV_RES) : 0;
	H > H_MAX ? error_inv_n(wolf, ERR_H_MAX, H_MAX) : 0;
	W > W_MAX ? error_inv_n(wolf, ERR_W_MAX, W_MAX) : 0;
}



t_vector4d		t_vec4_new(float x, float y, float z, float w)
{
	t_vector4d	v4;

	v4.x = x;
	v4.y = y;
	v4.z = z;
	v4.w = w;
	return (v4);
}

t_vector4d		vec4_m4_mult(t_vector4d vec4, t_matrix4 m4)
{
	t_vector4d	new;

	new.x = vec4.x * m4.matrix[0] + vec4.y * m4.matrix[1] + \
		vec4.z * m4.matrix[2] + vec4.w * m4.matrix[3];
	new.y = vec4.x * m4.matrix[4] + vec4.y * m4.matrix[5] + \
		vec4.z * m4.matrix[6] + vec4.w * m4.matrix[7];
	new.z = vec4.x * m4.matrix[8] + vec4.y * m4.matrix[9] + \
		vec4.z * m4.matrix[10] + vec4.w * m4.matrix[11];
	new.w = vec4.x * m4.matrix[12] + vec4.y * m4.matrix[13] + \
		vec4.z * m4.matrix[14] + vec4.w * m4.matrix[15];
	return (new);
}

t_matrix4		m4_mult(t_matrix4 *mat_a, t_matrix4 *mat_b)
{
	int			i;
	int			j;
	int			k;
	t_matrix4	new;
	
	ft_memset(&new, 0, sizeof(t_matrix4));
	i = -1;
	while (++i < M4_SIDE)
	{
		j = -1;
		while (++j < M4_SIDE)
		{
			k = -1;
			while (++k < M4_SIDE)
				new.matrix[i * M4_SIDE + j] += \
				mat_a->matrix[i * M4_SIDE + k] * \
				mat_b->matrix[k * M4_SIDE + j];
		}
	}
	return new;
}


void			print_t_matrix(t_matrix4 *matrix)
{
	int			i;
	int			j;

	i = -1;
	while (++i < M4_ROWS)
	{
		j = -1;
		while (++j < M4_COLUMNS)
		{
			ft_printf("%f ", matrix->matrix[i * M4_COLUMNS + j]);
		}
		ft_printf("\n");
	}
	
}

/*
int				main(int argc, char **argv)
{
	t_wolf		*wolf;

	(void)argv;
	
	wolf = NULL;
	wolf = t_wolf_new();
	validate_const(wolf);
	argc != 2 ? error(wolf, ERR_USAGE) : 0;
	SDL_Init(SDL_INIT_EVERYTHING) != 0 ? error(wolf, SDL_GetError()) : 0;
	TTF_Init() != 0 ? error(wolf, SDL_GetError()) : 0;

	


	
	
	init_map(wolf, argv[1]);
	init_player(wolf, wolf->player, wolf->map);
	init_bonus(wolf);
	music(wolf->bon);
	init_tex_arr(wolf);
	
	wolf_loop(wolf);
	return (0);
}
*/


int				main(void)
{
	
	t_matrix4 a;
	t_matrix4 b;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a.matrix[i * M4_ROWS + j] = 2. * (j + i);
			b.matrix[i * M4_ROWS + j] = 12. * (j + i);
		}
	}
	print_t_matrix(&b);
	t_vector4d v = (t_vector4d){2,3,4,5};
	ft_printf("%f %f %f %f", v.x, v.y, v.z, v.w);
	v = vec4_m4_mult(v, a);
}

