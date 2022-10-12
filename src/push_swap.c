#include "../inc/push_swap.h"

int	run_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *a;
	t_stack *b;
	int	len_a;

	a = *stack_a;
	b = *stack_b;
	len_a = ft_list_len(a);
	if (len_a == 1)
		return (0);
	else if (len_a == 2)
		algo2(&a);
	else
		sort_stack(&a, &b);
	*stack_a = a;
	*stack_b = b;
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

int	to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack *b;
	int	counter;

	a = *stack_a;
	b = *stack_b;
	counter = 0;
	while (a)
	{
		if (a->index <= counter)
		{
			pb(&a, &b);
			rb(&b);
			counter++;
		}
		else if (a->index == counter + 1)
		{
			pb(&a, &b);
			counter++;
		}
		else
			ra(&a);
	}
	*stack_a = a;
	*stack_b = b;
	return (--counter);
}

int	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		counter;

	a = *stack_a;
	b = *stack_b;
	counter = to_stack_b(&a, &b);
	while (b)
	{
		if (b->index == counter)
			pa(&a, &b);
		else
		{
			rrb(&b);
			pa(&a, &b);
		}
		counter--;
	}
	*stack_a = a;
	*stack_b = b;
	return (0);
}
