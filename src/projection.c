#include "wolf3d.h"

static	t_matrix4	init_projection_matrix(t_projection *proj)
{
	t_matrix4	projection_matrix;
	float		m00;
	float		m11;
	float		m22;
	float		m32;

	m00 = 2 / (proj->right - proj->left);
	m11 = 2 / (proj->top - proj->bottom);
	m22 = (proj->far + proj->near) / (proj->far - proj->near);
	m32 = -2 * proj->near * proj->far / (proj->far - proj->near);
	projection_matrix = (t_matrix4){
			m00, 0.f, 0.f, 0.f,
			0.f, m11, 0.f, 0.f,
			0.f, 0.f, m22, 1.f,
			0.f, 0.f, m32, 0.f
		};
	return (projection_matrix);
}

static	t_matrix4	init_to_screen_matrix(t_render *render)
{
	t_matrix4	to_screen_matrix;
	float		hw;
	float		hh;

	hw = render->half_width;
	hh = render->half_height;
	to_screen_matrix = (t_matrix4){
			hw, 0.f, 0.f, 0.f,
			0.f, -hh, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			hw, hh, 0.f, 1.f
		};
	return (to_screen_matrix);
}

static t_projection	*t_projection_new(t_render *render)
{
	t_projection	*new;

	if (!(new = ft_memalloc(sizeof(t_projection))))
		return NULL;
	new->near = render->camera->near_plane;
	new->far = render->camera->far_plane;
	new->right = tanf(render->camera->h_fov / 2);
	new->left = -new->right;
	new->top = tanf(render->camera->v_fov / 2);
	new->bottom = -new->top;
	return (new);
}

void			t_projection_init(t_render *render)
{
	t_projection	*new;

	new = t_projection_new(render);
	render->projection = new;
	new->projection_matrix = init_projection_matrix(new);
	new->to_screen_matrix = init_to_screen_matrix(render);
}


