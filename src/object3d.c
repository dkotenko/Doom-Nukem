#include "wolf3d.h"

void	vertices_normalize_and_reshape(t_vertex *vertex)
{
	vertex->vertex.x /= vertex->vertex.w;
	vertex->vertex.y /= vertex->vertex.w;
	vertex->vertex.z /= vertex->vertex.w;
	vertex->vertex.w /= vertex->vertex.w;
	if (
		vertex->vertex.x > 1 || vertex->vertex.x < - 1 ||
		vertex->vertex.y > 1 || vertex->vertex.y < - 1 ||
		vertex->vertex.z > 1 || vertex->vertex.z < - 1
		)
		vertex->to_draw = 0;
}

void	vertices_map_matrix(t_object *object, t_matrix4 matrix)
{
	int	i;
	int	j;
	//t_polygon *polygon;

	i = -1;
	while (++i < object->sector->curr_size)
	{
		j = -1;
		//polygon = object->sector->polygons[i];
		while (++j < object->sector->polygons[i]->curr_size)
		{
			object->sector->polygons[i]->vertices[j]->vertex = vec4_m4_mult(
				object->sector->polygons[i]->vertices[j]->vertex, matrix);
		}
	}
}

void	vertices_map_void(t_object *object, void (f)(t_vertex *))
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
			f(polygon->vertices[j]);
		}
	}
}

void	vertices_print(t_vertex *vertex)
{
	ft_printf("id: %d, to_draw: %d\n", 0, vertex->to_draw);
	print_t_vec4(vertex->vertex);
	print_t_vec4(vertex->vertex_origin);
}

void	t_object_print_vertices(t_render *render)
{	
	vertices_map_void(render->object, vertices_print);
	exit(0);
}

void	refresh_polygons(t_polygon *polygon)
{
	polygon->to_draw = 1;
}

void	refresh_vertices(t_vertex *vertex)
{
	vertex->vertex = vertex->vertex_origin;
	vertex->to_draw = 1;
}

void	fswap(float *a, float *b)
{
	float	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
void	draw_polygon(t_render *render, t_polygon *polygon)
{
	if (!polygon->to_draw)
		return ;
// Declare the arrays
	int	x_start[H];
	int	x_end [H];

	//ft_memset(x_start, W + 1, H);
	//ft_memset(x_end, 0, H);
	// Determine first and last line that the polygon covers
	int y_min = H + 1;
	int y_max = -1;
	for (int i=0; i<polygon->curr_size; i++)
	{   if (polygon->vertices[i]->vertex.y < y_min)
		y_min = polygon->vertices[i]->vertex.y;
		if (polygon->vertices[i]->vertex.y > y_max)
		y_max = polygon->vertices[i]->vertex.y;
	}
	
	if (y_min == y_max) return;
	// Initialize arrays for this range
	for (int i=y_min; i<y_max; i++)
	{   x_start[i]=W+1;
		x_end[i]=-1;
	}
	(void)render;
	// Trace edges
	for (int i=0; i<polygon->curr_size; i++)
	{   // Determine edge coordinates
		float x1 = polygon->vertices[i]->vertex.x;
		float y1 = polygon->vertices[i]->vertex.y;
		float x2;
		float y2;
		if (i < polygon->curr_size - 1)
		{
			x2 = polygon->vertices[(i + 1) % polygon->curr_size]->vertex.x;
			y2 = polygon->vertices[(i + 1) % polygon->curr_size]->vertex.y;
		}
		else
		{
			x2 = polygon->vertices[0]->vertex.x;
			y2 = polygon->vertices[0]->vertex.y;
		}
		
		// We want to draw from top to bottom
		if (y2<y1)
		{ 
			fswap (&y1, &y2);
			fswap (&x1, &x2);
		}
		// Determine slope of edge
		float deltax = (x2-x1)/(y2-y1);
		//ft_printf("%d\n", y2);
		for (int p=y1; p < y2; p++)
		{   int xpos = (int)x1;
			if (xpos < x_start[p]) x_start[p]=xpos;
			if (xpos > x_end[p]) x_end[p]=xpos;
			//if (x_end[p] > W) x_end[p] = W - 1;
			//ft_printf("xstart: %d xend:%d y:%d %d\n", x_start[p], x_end[p], p, xpos);
			
			//draw_line(render->surface, dot(x_start[p], p), dot(x_end[p], p), polygon->color);
			// Advance one screen line
			x1 += deltax;
		}
	}
	
	for (int i = 0; i < H; i++)
	{
		if (x_end[i] > 0 && x_end[i] < W && x_start[i] > 0 && x_start[i] < W)
			draw_line(render->surface, dot(x_start[i], i), dot(x_end[i], i), polygon->color);
	}
}
*/


void	draw_polygon(t_render *render, t_polygon *polygon)
{
	int	i;

	i = -1;
	while (++i < polygon->curr_size)
	{
		if (polygon->vertices[i]->to_draw)
		{
			if (i < polygon->curr_size - 1)
			{
				if (polygon->vertices[i + 1]->to_draw)
					draw_line(render->surface,
					dot(polygon->vertices[i]->vertex.x, polygon->vertices[i]->vertex.y),
					dot(polygon->vertices[i + 1]->vertex.x, polygon->vertices[i + 1]->vertex.y),
					polygon->color);
			}
			else
			{
				if (polygon->vertices[0]->to_draw)
					draw_line(render->surface,
					dot(polygon->vertices[i]->vertex.x, polygon->vertices[i]->vertex.y),
					dot(polygon->vertices[0]->vertex.x, polygon->vertices[0]->vertex.y),
					polygon->color);
			}
		}
	}
}


void	draw_polygons(t_render *render)
{
	int	i;

	i = -1;
	while (++i < render->object->sector->curr_size)
	{
		if (render->object->sector->polygons[i]->to_draw)
			draw_polygon(render, render->object->sector->polygons[i]);
		//ft_printf("here\n");
	}
}

void	set_polygon_draw(t_polygon *polygon)
{
	int	i;

	i = -1;
	while (++i < polygon->curr_size)
	{
		if (!polygon->vertices[i]->to_draw)
			polygon->to_draw = 0;
		return ;
	}
}

void	polygons_map_void(t_object *object, void (f)(t_polygon *))
{
	int	i;

	i = -1;
	while (++i < object->sector->curr_size)
	{
		f(object->sector->polygons[i]);
	}
}

void	screen_projection(t_render *render, t_object *object)
{
	polygons_map_void(object, refresh_polygons);
	vertices_map_void(object, refresh_vertices);
	
	vertices_map_matrix(object, get_camera_matrix(render->camera));
	vertices_map_matrix(object, render->projection->projection_matrix);
	
	vertices_map_void(object, vertices_normalize_and_reshape);
	polygons_map_void(object, set_polygon_draw);
	//vertices_normalize_and_reshape(object);
	
	vertices_map_matrix(object, render->projection->to_screen_matrix);
	
	
	//print_vertices(render);
	//polygons_map_void(object, draw_polygon);
	//print_t_polygon(render->object->sector->polygons[1]);
}

t_object *t_object_new(t_render *render, t_sector **sector)
{
	t_object *new = (t_object *)malloc(sizeof(t_object));
	(void)render;
	if (!new)
		return NULL;
	render->object = new;
	new->sector = *sector;
	vertices_translate(new, translate(t_vec3_new(0.0001, 0.0001, 0.0001)));
	return (new);
}