#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int			i;
	int			nbr;
	char		**matrix;
	char		*res;
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	i = -1;
	chek_num(ac, av);
	res = ft_strjoin(ac, av);
	matrix = ft_split(res);
	free(res);
	while (matrix[++i])
	{
		check_right_num(matrix[i]);
		nbr = ft_atoi(matrix[i]);
		append(&a, nbr);
		check_duble(&a);
	}
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
	pstr("SUCSESS!!!!\n");
	return (0);
}
