#include "bonus.h"

int	main(int ac, char **av)
{
	t_checker_args  data;
	t_stack			*stack_a;
	t_stack			*stack_b;
	data.ac = ac;
	data.av = av;
	stack_a = NULL;
	stack_b = NULL;
	data.iterator = -1;
	if (check_args(data, &stack_a))
		error_exit();
	data.str = get_next_line(0);
		
	if (data.str)
	{
		data.matrix = ft_split(data.str, '\n');
		check_algo(data.matrix, &stack_a, &stack_b);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}