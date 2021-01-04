#include "wolf3d.h"

t_polygon		*t_polygon_new(int vert_number, int color)
{
	t_polygon	*new;

	if (vert_number < 1)
		return NULL;
	new = (t_polygon *)malloc(sizeof(t_polygon));
	if (!new)
		return NULL;
	new->max_size = vert_number;
	new->curr_size = 0;
	new->vertices = (t_vertex **)malloc(sizeof(t_vertex *) *vert_number);
	new->color = color;
	if (!new->vertices)
		return NULL;
	if (!(new->vert_to_draw = (int *)malloc(sizeof(int) * vert_number)))
		return NULL;
	return (new);
}

void			t_polygon_add_vertex(t_polygon *polygon, t_vector4d to_add)
{
	t_vertex	*new;

	new = (t_vertex *)malloc(sizeof(t_vertex));
	if (!new)
		return ;
	new->vertex_origin = to_add;
	new->vertex = to_add;
	new->to_draw = 1;
	polygon->vertices[polygon->curr_size++] = new;
}

t_vector3d		t_polygon_get_centroid(t_polygon *polygon)
{
	int			i;
	t_vector4d	centroid;

	i = -1;
	ft_memset(&centroid, 0, sizeof(centroid));
	while (++i < polygon->curr_size)
	{
		centroid = t_vec4_add(
			centroid, polygon->vertices[i]->vertex_origin);
	}
	centroid = t_vec4_divn(centroid, polygon->curr_size);
	return (t_vec3_new(centroid.x, centroid.y, centroid.z));
	
}


void	print_t_polygon(t_polygon *polygon)
{
	int	i;

	i = -1;
	while (++i < polygon->curr_size)
	{
		print_t_vec4(polygon->vertices[i]->vertex_origin);
		print_t_vec4(polygon->vertices[i]->vertex);
	}
	
	exit(0);
}
