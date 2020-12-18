#include "wolf3d.h"

t_camera		*t_camera_new(t_vector3d position)
{
	t_camera	*new;

	if (!(new = (t_camera *)malloc(sizeof(t_camera))))
		return NULL;
	new->position = (t_vector4d){position.x, position.y, position.z, 1.f};
    new->forward = (t_vector4d){0.f, 0.f, 1.f, 1.f};
	new->up = (t_vector4d){0.f, 1.f, 0.f, 1.f};
	new->right = (t_vector4d){1.f, 0.f, 0.f, 1.f};
	new->h_fov = M_PI / 3;
	new->v_fov = new->h_fov * (H / W);
	new->near_plane = 0.1f;
	new->far_plane = 100.f;
	new->moving_speed = 0.3f;
	new->rotation_speed = 0.015f;
	return (new);
}

t_matrix4	get_camera_matrix(t_camera *camera)
{
	return (m4_mult(
		get_translated_matrix(camera),
		get_rotated_matrix(camera)));
}


t_matrix4	get_translated_matrix(t_camera *camera)
{
	return ((t_matrix4){ .matrix =
		{
			1.f, 0.f, 0.f, 0.f, \
			0.f, 1.f, 0.f, 1.f, \
			0.f, 0.f, 1.f, 0.f, \
			-camera->position.x, -camera->position.y, \
			-camera->position.z, 1.f}});
}

t_matrix4	get_rotated_matrix(t_camera *camera)
{
	return ((t_matrix4){ .matrix =
		{
			camera->right.x, camera->up.x, camera->forward.x, 0.f, \
			camera->right.y, camera->up.y, camera->forward.y, 0.f, \
			camera->right.z, camera->up.z, camera->forward.z, 0.f, \
			0.f, 0.f, 0.f, 1.f}});
}

void		camera_yaw(t_camera *camera, float angle)
{
	t_matrix4	rotate;

	rotate = rotate_y(angle);
	camera->forward = vec4_m4_mult(camera->forward, rotate);
	camera->right = vec4_m4_mult(camera->right, rotate);
	camera->up = vec4_m4_mult(camera->up, rotate);
}

void		camera_pitch(t_camera *camera, float angle)
{
	t_matrix4	rotate;

	rotate = rotate_x(angle);
	camera->forward = vec4_m4_mult(camera->forward, rotate);
	camera->right = vec4_m4_mult(camera->right, rotate);
	camera->up = vec4_m4_mult(camera->up, rotate);
}