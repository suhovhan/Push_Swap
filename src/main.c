#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	int			nbr;
	char		**matrix;
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	i = -1;
	chek_num(ac, av);
	matrix = ft_split(ft_strjoin(ac, av));
	while (matrix[++i])
	{
		check_right_num(matrix[i]);
		nbr = ft_atoi(matrix[i]);
		append(&a, nbr);
	}
	check_duble(&a);
	get_index(&a);
	run_algo(&a, &b);
	// while (a)
	// {
	// 	printf("nb = %d  index = %d\n", a->nb, a->index);
	// 	a = a->next;
	// }
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
	return (0);
}
