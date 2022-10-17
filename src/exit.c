/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 07:22:23 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/17 07:22:25 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	free_and_exit(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*tmp;

	a = *stack_a;
	tmp = a->next;
	while (tmp)
	{
		free(a);
		a = tmp;
		tmp = tmp->next;
	}
	exit(0);
	return (0);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
