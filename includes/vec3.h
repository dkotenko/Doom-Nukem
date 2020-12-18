#ifndef VEC3_H
# define VEC3_H

#include <math.h>

typedef struct	s_vector3d
{
	float		x;
	float		y;
	float		z;
}				t_vector3d;

static inline t_vector3d vec3(float x, float y, float z)        { return (t_vector3d){ x, y, z }; }
static inline t_vector3d v3_add   (t_vector3d a, t_vector3d b)          { return (t_vector3d){ a.x + b.x, a.y + b.y, a.z + b.z }; }
static inline t_vector3d v3_adds  (t_vector3d a, float s)           { return (t_vector3d){ a.x + s,   a.y + s,   a.z + s   }; }
static inline t_vector3d v3_sub   (t_vector3d a, t_vector3d b)          { return (t_vector3d){ a.x - b.x, a.y - b.y, a.z - b.z }; }
static inline t_vector3d v3_subs  (t_vector3d a, float s)           { return (t_vector3d){ a.x - s,   a.y - s,   a.z - s   }; }
static inline t_vector3d v3_mul   (t_vector3d a, t_vector3d b)          { return (t_vector3d){ a.x * b.x, a.y * b.y, a.z * b.z }; }
static inline t_vector3d v3_muls  (t_vector3d a, float s)           { return (t_vector3d){ a.x * s,   a.y * s,   a.z * s   }; }
static inline t_vector3d v3_div   (t_vector3d a, t_vector3d b)          { return (t_vector3d){ a.x / b.x, a.y / b.y, a.z / b.z }; }
static inline t_vector3d v3_divs  (t_vector3d a, float s)           { return (t_vector3d){ a.x / s,   a.y / s,   a.z / s   }; }

static inline t_vector3d v3_norm  (t_vector3d v);
static inline float  v3_dot   (t_vector3d a, t_vector3d b)          { return a.x*b.x + a.y*b.y + a.z*b.z;                 }
static inline t_vector3d v3_proj  (t_vector3d v, t_vector3d onto);
static inline t_vector3d v3_cross (t_vector3d a, t_vector3d b);
static inline float  v3_angle_between(t_vector3d a, t_vector3d b);

static inline float  v3_len(t_vector3d v)                    { return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);          }
static inline t_vector3d v3_norm(t_vector3d v);
static inline t_vector3d v3_norm(t_vector3d v) {
	float len = v3_len(v);
	if (len > 0)
		return (t_vector3d){ v.x / len, v.y / len, v.z / len };
	else
		return (t_vector3d){0, 0, 0};
}

#endif