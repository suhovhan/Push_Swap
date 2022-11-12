/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:58:06 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:58:08 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ra(t_stack **head_a, int i)
{
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*ptr;

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
	if (i == 1)
		write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **head_b, int i)
{
	t_stack	*b;
	t_stack	*tmp;
	t_stack	*ptr;

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
	if (i == 1)
		write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **head_a, t_stack **head_b, int i)
{
	ra(head_a, i);
	rb(head_b, i);
	if (i == 1)
		write(1, "rr\n", 3);
	return (0);
}
