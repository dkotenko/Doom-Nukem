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


