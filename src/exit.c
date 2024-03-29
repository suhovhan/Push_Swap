/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 07:22:23 by suhovhan          #+#    #+#             */
/*   Updated: 2023/02/13 17:07:41 by suhovhan         ###   ########.fr       */
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
	while (1)
		;
	exit(0);
	return (0);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
	return (0);
}

void	free_error_exit(t_stack **stack_a, t_stack **stack_b, char **matrix)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*stack_a);
	tmp2 = (*stack_b);
	while (tmp)
	{
		*(stack_a) = (*stack_a)->next;
		free(tmp);
		tmp = (*stack_a);
	}
	while (tmp2)
	{
		*(stack_b) = (*stack_b)->next;
		free(tmp2);
		tmp2 = (*stack_b);
	}
	free_matrix(matrix);
	write(2, "Error\n", 6);
	exit(0);
}
