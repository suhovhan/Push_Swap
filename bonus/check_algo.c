/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:35:10 by suhovhan          #+#    #+#             */
/*   Updated: 2022/12/01 17:38:34 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bonus.h"

void	chek_algo_half(int i, char **mtx, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	if (!ft_strncmp(mtx[i], "ra", 3))
		ra(&a, 0);
	else if (!ft_strncmp(mtx[i], "rb", 3))
		rb(&b, 0);
	else if (!ft_strncmp(mtx[i], "rr", 3))
		rr(&a, &b, 0);
	else if (!ft_strncmp(mtx[i], "rra", 4))
		rra(&a, 0);
	else if (!ft_strncmp(mtx[i], "rrb", 4))
		rrb(&b, 0);
	else if (!ft_strncmp(mtx[i], "rrr", 4))
		rrr(&a, &b, 0);
	else
		free_error_exit(stack_a, stack_b, mtx);
	*stack_a = a;
	*stack_b = b;
}

int	check_algo(char **matrix, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = -1;
	a = *stack_a;
	b = *stack_b;
	while (matrix[++i])
	{
		if (!ft_strncmp(matrix[i], "pa", 3))
			pa(&a, &b, 0);
		else if (!ft_strncmp(matrix[i], "pb", 3))
			pb(&a, &b, 0);
		else if (!ft_strncmp(matrix[i], "sa", 3))
			sa(&a, 0);
		else if (!ft_strncmp(matrix[i], "sb", 3))
			sb(&b, 0);
		else if (!ft_strncmp(matrix[i], "ss", 3))
			ss(&a, &b, 0);
		else
			chek_algo_half(i, matrix, &a, &b);
	}
	*stack_a = a;
	*stack_b = b;
	return (0);
}
