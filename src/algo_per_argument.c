/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_per_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:03:58 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 23:04:00 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->index + 1 != a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
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
	if (a->next->index == 3)
		sa(&a);
	else if (a->next->next->index == 3)
	{
		rra(&a);
		rra(&a);
	}
	else if (a->next->next->next->index == 3)
		rra(&a);
	comb_algo4(&a, &b);
	*stack_a = a;
	*stack_b = b;
	return (0);
}

int	algo5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	if (a->next->index == 4)
		sa(&a);
	else if (a->next->next->index == 4)
	{
		ra(&a);
		sa(&a);
	}
	else if (a->next->next->next->index == 4)
	{
		rra(&a);
		rra(&a);
	}
	else if (a->next->next->next->next->index == 4)
		rra(&a);
	comb_algo5(&a, &b);
	*stack_a = a;
	*stack_b = b;
	return (0);
}
