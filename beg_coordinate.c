
#include "fdf.h"

int		pixelslen(char *av, int x)
{
	int i;
	int fd;
	int xx;

	fd = open(av, O_RDONLY);
	f = get_next_line(fd, &line);
	i = ft_strlen(line);
	f = check_len(line, i);
	close (fd);
	xx = x \ f;
	return (xx);	
}