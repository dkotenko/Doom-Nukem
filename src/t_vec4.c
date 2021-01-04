/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sdl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:31:59 by clala             #+#    #+#             */
/*   Updated: 2020/10/18 19:43:59 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_vector4d t_vec4_sub(t_vector4d a, t_vector4d b)
{
	return ((t_vector4d){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w});
}

t_vector4d t_vec4_add(t_vector4d a, t_vector4d b)
{
	return ((t_vector4d){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_vector4d t_vec4_muln(t_vector4d a, float n)
{
	return ((t_vector4d){a.x * n, a.y * n, a.z * n, a.w * n});
}

t_vector4d		vec4_m4_mult(t_vector4d vec4, t_matrix4 m4)
{
	t_vector4d	new;

	new.x = vec4.x * m4.matrix[0] + vec4.y * m4.matrix[4] + \
		vec4.z * m4.matrix[8] + vec4.w * m4.matrix[12];
	new.y = vec4.x * m4.matrix[1] + vec4.y * m4.matrix[5] + \
		vec4.z * m4.matrix[9] + vec4.w * m4.matrix[13];
	new.z = vec4.x * m4.matrix[2] + vec4.y * m4.matrix[6] + \
		vec4.z * m4.matrix[10] + vec4.w * m4.matrix[14];
	new.w = vec4.x * m4.matrix[3] + vec4.y * m4.matrix[7] + \
		vec4.z * m4.matrix[11] + vec4.w * m4.matrix[15];
	return (new);
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

t_vector4d t_vec4_divn  (t_vector4d a, float n)
{
	return (t_vector4d){ a.x / n,   a.y / n,   a.z / n, a.w / n };
}

void	print_t_vec4(t_vector4d v)
{
	ft_printf("x: %f , y: %f, z: %f, w: %f\n", v.x, v.y, v.z, v.w);
}