#include "wolf3d.h"

static	t_matrix4	*init_projection_matrix(t_camera *camera)
{
	t_matrix4	*projection_matrix;
	float		m00;
	float		m11;
	float		m22;
	float		m32;

	m00 = 2 / (tanf()



}

static	t_matrix4	*init_to_screen_matrix()
{
	t_matrix4	*to_screen_matrix;


}

t_projection	*t_projection_new(t_render *render)
{
	t_projection	*new;

	if (!(new = ft_memalloc(sizeof(t_projection))))
		return NULL;
	new->projection_matrix = init_projection_matrix(render->camera);
	if (!new->projection_matrix)
		return NULL;
	new->to_screen_matrix = init_to_screen_matrix();
	if (!new->to_screen_matrix)
		return NULL;
}


