#include "bonus.h"

int	check_algo(char **matrix, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = -1;
	a = *stack_a;
	b = *stack_b;
	while (matrix[++i])
	{
		if (!ft_strncmp(matrix[i], "pa", 3))
			pa(&a, &b, 0);
		else if (!ft_strncmp(matrix[i], "pb", 3))
			pb(&a, &b, 0);
		else if (!ft_strncmp(matrix[i], "sa", 3))
			sa(&a, 0);
		else if (!ft_strncmp(matrix[i], "sb", 3))
			sb(&b, 0);
		else if (!ft_strncmp(matrix[i], "ss", 3))
			ss(&a, &b, 0);
		else if (!ft_strncmp(matrix[i], "ra", 3))
			ra(&a, 0);
		else if (!ft_strncmp(matrix[i], "rb", 3))
			rb(&b, 0);
		else if (!ft_strncmp(matrix[i], "rr", 3))
			rr(&a, &b, 0);
		else if (!ft_strncmp(matrix[i], "rra", 4))
			rra(&a, 0);
		else if (!ft_strncmp(matrix[i], "rrb", 4))
			rrb(&b, 0);
		else if (!ft_strncmp(matrix[i], "rrr", 4))
			rrr(&a, &b, 0);
		else
			error_exit();
	}
	*stack_a = a;
	*stack_b = b;
	return (0);
}