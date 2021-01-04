#include "wolf3d.h"

t_vector3d		t_vec3_new(float x, float y, float z)
{
	t_vector3d	v3;

	v3.x = x;
	v3.y = y;
	v3.z = z;
	return (v3);
}