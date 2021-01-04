#include "wolf3d.h"

t_matrix4	translate(t_vector3d position)
{
	return ((t_matrix4){ .matrix =
		{
			1.f, 0.f, 0.f, 0.f, \
			0.f, 1.f, 0.f, 0.f, \
			0.f, 0.f, 1.f, 0.f, \
			position.x, position.y, position.z, 1.f}});
}

t_matrix4	rotate_x(float angle)
{
	return ((t_matrix4){ .matrix =
		{
			1.f, 0.f, 0.f, 0.f, \
			0.f, cosf(angle), sinf(angle), 0.f, \
			0.f, -sinf(angle), cosf(angle), 0.f, \
			0.f, 0.f, 0.f, 1.f}});
}

t_matrix4	rotate_y(float angle)
{
	return ((t_matrix4){ .matrix =
		{
		cosf(angle), 0.f, -sinf(angle), 0.f, \
		0.f, 1.f, 0.f, 0.f, \
		sinf(angle), 0.f, cosf(angle), 0.f, \
		0.f, 0.f, 0.f, 1.f }});
}

t_matrix4	rotate_z(float angle)
{
	return ((t_matrix4){ .matrix =
		{
		cosf(angle), sinf(angle), 0.f, 0.f, \
		-sinf(angle), cosf(angle), 0.f, 0.f,\
		0.f, 0.f, 1.f, 0.f, \
		0.f, 0.f, 0.f, 1.f }});
}

t_matrix4	scale(float n)
{
	return ((t_matrix4){ .matrix =
		{
		n, 0.f, 0.f, 0.f, \
		0.f, n, 0.f, 0.f, \
		0.f, 0.f, n, 0.f, \
		0.f, 0.f, 0.f, n }});
}
