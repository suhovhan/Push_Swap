/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:58:13 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:58:15 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	write(1, "rrb\n", 4);
	*head_b = tmp;
	return (0);
}

int	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(head_a);
	rrb(head_b);
	write(1, "rrr\n", 4);
	return (0);
}
