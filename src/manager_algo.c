/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 07:19:56 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/17 07:19:58 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	comb_algo4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	pb(&a, &b);
	algo3(&a);
	pa(&a, &b);
	ra(&a);
	*stack_a = a;
	*stack_b = b;
	return (0);
}

int	comb_algo5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	pb(&a, &b);
	algo4(&a, &b);
	pa(&a, &b);
	ra(&a);
	*stack_a = a;
	*stack_b = b;
	return (0);
}
