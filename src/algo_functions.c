#include "../inc/push_swap.h"

int	pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;
	t_stack	*a;
	t_stack	*b;

	a = *head_a;
	b = *head_b;
	if (b == NULL)
		return (0);
	tmp = b;
	b = tmp->next;
	tmp->next = a;
	a = tmp;
	*head_a = a;
	*head_b = b;
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;
	t_stack	*a;
	t_stack	*b;

	a = *head_a;
	b = *head_b;
	if (a == NULL)
		return (0);
	tmp = a;
	a = tmp->next;
	tmp->next = b;
	b = tmp;
	*head_a = a;
	*head_b = b;
	write(1, "pb\n", 3);
	return (0);
}

int	sa(t_stack **head_a)
{
	t_stack *tmp;
	t_stack *a;

	a = *head_a;
	tmp = a->next;
	a->next = tmp->next;
	tmp->next = a;
	a = tmp;
	*head_a = a;
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack **head_b)
{
	t_stack *tmp;
	t_stack *b;

	b = *head_b;
	tmp = b->next;
	b->next = tmp->next;
	tmp->next = b;
	b = tmp;
	*head_b = b;
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack **head_a, t_stack **head_b)
{
	sa(head_a);
	sb(head_b);
	write(1, "ss\n", 3);
	return (0);
}

int	ra(t_stack **head_a)
{
	t_stack *a;
	t_stack *tmp;
	t_stack *ptr;

	a = *head_a;
	if (!a || !a->next)
		return (0);
	tmp = a->next;
	ptr = tmp;
	a->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a;
	*head_a = ptr;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **head_b)
{
	t_stack *b;
	t_stack *tmp;
	t_stack *ptr;

	b = *head_b;
	if (!b || !b->next)
		return (0);
	tmp = b->next;
	ptr = tmp;
	b->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = b;
	*head_b = ptr;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **head_a, t_stack **head_b)
{
	ra(head_a);
	rb(head_b);
	write(1, "rr\n", 3);
	return (0);
}

int	rra(t_stack **head_a)
{
	t_stack	*a;
	t_stack	*tmp;

	a = *head_a;
	tmp = a;
	if (!a || !a->next)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	while (a->next != tmp)
		a = a->next;
	a->next = NULL;
	tmp->next = *head_a;
	*head_a = tmp;
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack **head_b)
{
	t_stack	*b;
	t_stack	*tmp;

	b = *head_b;
	tmp = b;
	if (!b || !b->next)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	while (b->next != tmp)
		b = b->next;
	b->next = NULL;
	tmp->next = *head_b;
	*head_b = tmp;
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(head_a);
	rrb(head_b);
	write(1, "rrr\n", 4);
	return (0);
}