#include "wolf3d.h"

void	vertices_rotate_x(t_object *object, float value)
{
	vertices_map_matrix(object, rotate_x(value));
}

void	vertices_rotate_y(t_object *object, float value)
{
	vertices_map_matrix(object, rotate_y(value));
}

void	vertices_rotate_z(t_object *object, float value)
{
	vertices_map_matrix(object, rotate_z(value));
}

void	vertices_rotate_scale(t_object *object, float value)
{
	vertices_map_matrix(object, scale(value));
}

void	vertices_translate(t_object *object, t_matrix4 matrix)
{
	int	i;
	int	j;
	t_polygon *polygon;

	i = -1;
	while (++i < object->sector->curr_size)
	{
		j = -1;
		polygon = object->sector->polygons[i];
		while (++j < polygon->curr_size)
		{
			polygon->vertices[j]->vertex_origin = vec4_m4_mult(
				polygon->vertices[j]->vertex_origin, matrix);
		}
	}	
}
