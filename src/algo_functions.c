/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:36:01 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:36:04 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_stack	*tmp;
	t_stack	*a;

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
	t_stack	*tmp;
	t_stack	*b;

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
