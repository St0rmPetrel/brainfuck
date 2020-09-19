#include "../head/brainfuck.h"
#include "../head/read_in_big_string.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*code;

	i = 1;
	if (argc == 1)
	{
		fd = 0;
		code = read_in_big_string(0);
		brainfuck(code);
		free(code);
	}
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			code = read_in_big_string(fd);
			close(fd);
			brainfuck(code);
			free(code);
			i++;
		}
	}
}
