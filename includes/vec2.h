#include <math.h>

typedef struct s_vec2 {
	double x;
	double y;
}				t_vec2;

double magnitude2d(t_vec2 v);
t_vec2 normalize2d(t_vec2 v);
t_vec2 normal2d(t_vec2 v);
t_vec2 reverse2d(t_vec2 v);
t_vec2 add2d(t_vec2 v1, t_vec2 v2);
t_vec2 subtract2d(t_vec2 v1, t_vec2 v2);
double distance2d(t_vec2 v1, t_vec2 v2);
t_vec2 scalar_multiply2d(double k, t_vec2 v);
double dot2d(t_vec2 v1, t_vec2 v2);
t_vec2 rotate2d(double radian, t_vec2 v);



