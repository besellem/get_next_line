# get_next_line
```c
int	get_next_line(int fd, char **line);
```
Use this function in a loop to read an entire file, one line at a time.
You can use it with multiple file descriptors even in the wrong order.

## Example
Use this main to read and display an entire file, line by line.
```c
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*ret;
	int	check;
	int	fd;

	if (ac != 2)
	{
		dprintf(2, "%s: arg error\n", av[0]);
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == 1)
	{
		dprintf(2, "%s: file error\n", av[0]);
		return (1);
	}
	while ((check = get_next_line(fd, &ret)) >= 0)
	{
		printf("[%s]\n", ret);
		free(ret);
		if (check == 0)
			break ;
	}
	close(fd);
	return (0);
}

```
