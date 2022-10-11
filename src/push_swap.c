#include "../inc/push_swap.h"

int	run_algo(t_stack **a)
{
	t_stack *st_a;
	int	len_a;

	st_a = *a;
	len_a = ft_list_len(st_a);
	if (len_a == 1)
		return (0);
	else if (len_a == 2)
		algo2(&st_a);
	return (0);
}

int	algo2(t_stack **a)
{
	t_stack	*ptr;

	ptr = *a;
	if (ptr->index < ptr->next->index)
		return (0);
	else
		sa(a);
	return (0);
}
