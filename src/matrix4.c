#include "wolf3d.h"

t_matrix4		*t_matrix4_new(float values[M4_SIZE])
{
	t_matrix4	*new;
	int			i;

	if (!(new = (t_matrix4 *)malloc(sizeof(t_matrix4))))
		return NULL;
	ft_memset((void *)new->matrix, 0, sizeof(float) * M4_SIZE);
	if (values)
	{
		i = -1;
		while (++i < M4_SIZE)
			new->matrix[i] = values[i];
	}
	return (new);
}

t_matrix4		m4_mult(t_matrix4 mat_a, t_matrix4 mat_b)
{
	int			i;
	int			j;
	int			k;
	t_matrix4	new;
	float		a;
	float		*b;
	float		*c;

	i = -1;
	while (++i < M4_SIDE)
	{
		c = new.matrix + i * M4_SIDE;
		j = -1;
		while (++j < M4_SIDE)
			c[j] = 0;
		k = -1;
		while (++k < M4_SIDE)
		{
			b = mat_b.matrix + k * M4_SIDE;
			a = mat_a.matrix[i * M4_SIDE + k];
			j = -1;
			while (++j < M4_SIZE)
				new.matrix[i * M4_SIDE + j] += a * b[j];
		}
	}
	return (new);
}

void			print_t_matrix(t_matrix4 *matrix)
{
	int			i;
	int			j;

	i = -1;
	while (++i < M4_ROWS)
	{
		j = -1;
		while (++j < M4_COLUMNS)
		{
			ft_printf("%f ", matrix->matrix[i * M4_COLUMNS + j]);
		}
		ft_printf("\n");
	}
	exit(0);
}