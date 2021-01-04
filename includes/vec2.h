#include <math.h>

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

float magnitude2d(t_vec2 v);
t_vec2 normalize2d(t_vec2 v);
t_vec2 normal2d(t_vec2 v);
t_vec2 reverse2d(t_vec2 v);
t_vec2 add2d(t_vec2 v1, t_vec2 v2);
t_vec2 subtract2d(t_vec2 v1, t_vec2 v2);
float distance2d(t_vec2 v1, t_vec2 v2);
t_vec2 scalar_multiply2d(float k, t_vec2 v);
float dot2d(t_vec2 v1, t_vec2 v2);
t_vec2 rotate2d(float radian, t_vec2 v);



