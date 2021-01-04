#include "wolf3d.h"

t_sector		*t_sector_new(int polygons_number)
{
	t_sector	*new;
	new = (t_sector *)malloc(sizeof(t_sector));
	if (!new)
		return NULL;
	new->curr_size = 0;
	new->max_size = polygons_number;
	new->polygons = \
		(t_polygon **)malloc(sizeof(t_polygon *) * polygons_number);
	new->centroids_dist = (float *)malloc(sizeof(float) * polygons_number);
	new->z_buf = (int *)malloc(sizeof(int) * W * H);
	if (!new->polygons || !new->centroids_dist)
		return NULL;
	return (new);
}

void			t_sector_add_polygon(t_sector *sector, t_polygon *polygon)
{
	sector->polygons[sector->curr_size++] = polygon;
}

void			t_sector_get_centroids(t_sector *sector)
{
	int			i;
	t_vector3d	temp;

	i = -1;
	while (++i < sector->curr_size)
	{
		temp = t_polygon_get_centroid(sector->polygons[i]);
		sector->centroids_dist[i] = v3_len(temp);
	}
}