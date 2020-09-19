#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	brainfuck(char *str)
{
	char	*cell;
	char	*begin_cell;
	char	*begin_str;

	cell = malloc(2048);
	bzero(cell, 2048);
	begin_cell = cell;
	begin_str = str;
	while (*str != '\0')
	{
		if (str < begin_str)
		{
				write(1, "You are out of range\n", 22);
				break;
		}
		if (*str == '>')
			cell++;
		if (*str == '<')
			cell--;
		if (*str == '.')
			write(1, cell, 1);
		if (*str == '+')
			*cell += 1;
		if (*str == '-')
			*cell -= 1;
		if ((*str == '[') && (*cell == 0))
			while ((*str != ']') && (*str != '\0'))
			{
				str++;
				if (*str == '[')
				{
					while (*str != ']')
						str++;
					str++;
				}
			}
		if ((*str == ']') && (*cell != 0))
			while (*str != '[')
			{
				str--;
				if (*str == ']')
				{
					while (*str != '[')
						str--;
					str--;
				}
			}
		str++;
	}
	free(begin_cell);
}
