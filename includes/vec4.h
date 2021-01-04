#include <math.h>

typedef struct	s_vector4d
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vector4d;

t_vector4d	t_vec4_divn  (t_vector4d a, float n);
t_vector4d	t_vec4_new(float x, float y, float z, float w);

t_vector4d	t_vec4_sub(t_vector4d a, t_vector4d b);
t_vector4d	t_vec4_muln(t_vector4d a, float n);
t_vector4d	t_vec4_add(t_vector4d a, t_vector4d b);
