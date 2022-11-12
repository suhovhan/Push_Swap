/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:36:35 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:36:38 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	run_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		len_a;

	a = *stack_a;
	b = *stack_b;
	len_a = ft_list_len(a);
	if (is_sorted(a))
		free_and_exit(stack_a);
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

t_algo	algo_meneger(t_stack **stack_a, t_stack **stack_b, t_algo data)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	while (a)
	{
		if (a->index <= data.counter)
		{
			pb(&a, &b, 1);
			rb(&b, 1);
			data.counter++;
		}
		else if (a->index <= data.counter + data.n)
		{
			pb(&a, &b, 1);
			data.counter++;
		}
		else
			ra(&a, 1);
	}
	*stack_a = a;
	*stack_b = b;
	return (data);
}

t_algo	to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
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
	data = algo_meneger(&a, &b, data);
	data.counter--;
	*stack_a = a;
	*stack_b = b;
	return (data);
}

int	max_node_to_start(t_stack **stack_b, t_algo data)
{
	t_stack	*b;
	t_stack	*tmp;
	int		pos;

	b = *stack_b;
	tmp = b;
	data.iterator = -1;
	pos = 1;
	while (++data.iterator < data.n)
	{
		if (tmp->index == data.counter)
			pos = -1;
		else
			tmp = tmp->next;
	}
	while (data.counter && b->index != data.counter)
	{
		if (pos == -1)
			rb(&b, 1);
		else
			rrb(&b, 1);
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
		pa(&a, &b, 1);
		data.counter--;
	}
	*stack_a = a;
	*stack_b = b;
	return (0);
}
