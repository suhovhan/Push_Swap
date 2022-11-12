#include "bonus.h"

int	check_args(t_checker_args	data, t_stack **stack_a)
{
	t_stack	*a;

	a = *stack_a;
	chek_num(data.ac, data.av);
	data.iterator = -1;
	data.str = ft_strjoin(data.ac, data.av);
	data.matrix = ft_split(data.str, ' ');
	while (data.matrix[++data.iterator])
	{
		check_right_num(data.matrix[data.iterator]);
		data.nbr = ft_atoi(data.matrix[data.iterator]);
		append(&a, data.nbr);
	}
	check_duble(&a);
	get_index(&a);
	data.iterator = -1;
	while (data.matrix[++data.iterator])
		free(data.matrix[data.iterator]);
	free(data.matrix);
	free(data.str);
	*stack_a = a;
	return (0);
}