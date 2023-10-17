#include "cube.h"

int skip_spaces(char *buf, int i)
{
	while (buf[i] == ' ')
		i++;
	return (i);
}
