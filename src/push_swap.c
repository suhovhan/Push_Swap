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
	else if (len_a == 3)
		algo3(&a);
	else if (len_a == 4)
		algo4(&a, &b);
	else if (len_a == 5)
		algo5(&a, &b);
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


int	algo3(t_stack **stack_a)
{
	t_stack	*ptr;

	ptr = *stack_a;
	if (ptr->index == 0 && ptr->next->index == 1)
		return (0);
	else if (ptr->index == 0 && ptr->next->index == 2)
	{
		rra(&ptr);
		sa(&ptr);
	}
	else if (ptr->index == 1 && ptr->next->index == 0)
		sa(&ptr);
	else if (ptr->index == 1 && ptr->next->index == 2)
		rra(&ptr);
	else if (ptr->index == 2 && ptr->next->index == 0)
		ra(&ptr);
	else if (ptr->index == 2 && ptr->next->index == 1)
	{
		ra(&ptr);
		sa(&ptr);
	}
	*stack_a = ptr;
	return (0);
}

int	algo4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	if (a->index == 3)
	{
		pb(&a, &b);
		algo3(&a);
		pa(&a, &b);
		ra(&a);
	}
	else if (a->next->index == 3)
	{
		sa(&a);
		pb(&a, &b);
		algo3(&a);
		pa(&a, &b);
		ra(&a);
	}
	else if (a->next->next->index == 3)
	{
		rra(&a);
		rra(&a);
		pb(&a, &b);
		algo3(&a);
		pa(&a, &b);
		ra(&a);
	}
	else
	{
		rra(&a);
		pb(&a, &b);
		algo3(&a);
		pa(&a, &b);
		ra(&a);
	}
	*stack_a = a;
	*stack_b = b;
	return (0);
}

int	algo5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *a;
	t_stack *b;

	a = *stack_a;
	b = *stack_b;
	if (a->index == 4)
	{
		pb(&a, &b);
		algo4(&a, &b);
		pa(&a, &b);
		ra(&a);
	}
	else if (a->next->index == 4)
	{
		sa(&a);
		pb(&a, &b);
		algo4(&a, &b);
		pa(&a, &b);
		ra(&a);
	}
	else if (a->next->next->index == 4)
	{
		ra(&a);
		sa(&a);
		pb(&a, &b);
		algo4(&a, &b);
		pa(&a, &b);
		ra(&a);
	}
	else if (a->next->next->next->index == 4)
	{
		rra(&a);
		rra(&a);
		pb(&a, &b);
		algo4(&a, &b);
		pa(&a, &b);
		ra(&a);
	}
	else
	{
		rra(&a);
		pb(&a, &b);
		algo4(&a, &b);
		pa(&a, &b);
		ra(&a);
	}
	*stack_a = a;
	*stack_b = b;
	return (0);
}

t_algo	to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack *b;
	t_algo	data;

	a = *stack_a;
	b = *stack_b;
	data.counter = 0;
	if (ft_list_len(a) <= 60)
		data.n = 1;
	else if (ft_list_len(a) <= 100)
		data.n = 15;
	else if (ft_list_len(a) <= 500)
		data.n = 30;
	else
		data.n = 60;
	while (a)
	{
		if (a->index <= data.counter)
		{
			pb(&a, &b);
			rb(&b);
			data.counter++;
		}
		else if (a->index <= data.counter + data.n)
		{
			pb(&a, &b);
			data.counter++;
		}
		else
			ra(&a);
	}
	data.counter--;
	*stack_a = a;
	*stack_b = b;
	return (data);
}

int	max_node_to_start(t_stack **stack_b, t_algo data)
{
	t_stack *b;
	int		pos;
	
	b = *stack_b;
	data.iterator = -1;
	pos = 1;
	while (++data.iterator < data.n)
		if (b->index == data.counter)
			pos = -1;
	while (data.counter && b->index != data.counter)
	{
		if (pos == -1)
			rb(&b);
		else
			rrb(&b);
	}
	*stack_b = b;
	return (0);
}

int	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	t_algo	data;

	a = *stack_a;
	b = *stack_b;
	data = to_stack_b(&a, &b);
	while (b)
	{
		max_node_to_start(&b, data);
		pa(&a, &b);
		data.counter--;
	}
	*stack_a = a;
	*stack_b = b;
	return (0);
}
