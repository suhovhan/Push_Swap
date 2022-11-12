#include "bonus.h"

int	check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '\n' || line[i] != 'p' \
			|| line[i] != 'a' || line[i] != 'b' \
			|| line[i] != 's' || line[i] != 'r' \
			|| line[i] != 'o' || line[i] != 'E' \
			|| line[i] != 'D')
			error_exit();
	return (0);
}
