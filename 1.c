#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>

typedef struct s_list
{
	struct s_list *next;
	int		a;
	
}
t_list;

t_list *new(void)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	new->next = NULL;
	new->a = -1;
	return new;
}

int	is_fd_valid(int fd)
{
	return (fcntl(fd, F_GETFL) != -1 || errno != EBADF);
}

int main()
{
	static int aa[FD_SETSIZE];
	t_list *list = new();
	int fd = 0;
	
	static t_list *a[1];
	
	a[0] = list;
	int b = open("1.c", O_RDONLY);
	printf("%d\n", FD_SETSIZE);
	close(b);
	b = open("1.c", O_RDONLY);
	printf("%d\n", b);
	close(b);
for (int i = 0; i < 10; i++)
{
	list->next = new();
	list = list->next;
}
	return (0);
}
