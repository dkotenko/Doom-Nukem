#include "vec2.h"

double magnitude2d(t_vec2 v) {
	return sqrt(10000 * (v.x * v.x + v.y * v.y)) / 100;
}

t_vec2 normalize2d(t_vec2 v) {
	double m = magnitude2d(v);
	return (t_vec2){v.x / m, v.y / m};
}

t_vec2 normal2d(t_vec2 v) {
	return (t_vec2){-(v.y), v.x};
}

t_vec2 reverse2d(t_vec2 v) {
	return (t_vec2){-(v.x), -(v.y)};
}

t_vec2 add2d(t_vec2 v1, t_vec2 v2) {
	return (t_vec2){v1.x + v2.x, v1.y + v2.y};
}

t_vec2 subtract2d(t_vec2 v1, t_vec2 v2) {
	return (t_vec2){v1.x - v2.x, v1.y - v2.y};
}

double distance2d(t_vec2 v1, t_vec2 v2) {
	return magnitude2d(subtract2d(v1, v2));
}

t_vec2 scalar_multiply2d(double k, t_vec2 v) {
	return (t_vec2){k * v.x, k * v.y};
}

double dot2d(t_vec2 v1, t_vec2 v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

t_vec2 rotate2d(double radian, t_vec2 v) {
	return (t_vec2){
		v.x * cos(radian) - v.y * sin(radian),
		v.x * sin(radian) + v.y * cos(radian)
	};
}