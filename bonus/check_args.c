/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:35:40 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/30 17:35:47 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bonus.h"

int	check_args(t_checker_args	data, t_stack **stack_a)
{
	t_stack	*a;

	a = *stack_a;
	chek_num(data.ac, data.av);
	data.iterator = -1;
	data.str = ft_strjoin(data.ac, data.av);
	data.matrix = ft_split(data.str, ' ');
	while (data.matrix[++data.iterator])
	{
		check_right_num(data.matrix[data.iterator]);
		data.nbr = ft_atoi(data.matrix[data.iterator]);
		append(&a, data.nbr);
	}
	check_duble(&a);
	get_index(&a);
	data.iterator = -1;
	while (data.matrix[++data.iterator])
		free(data.matrix[data.iterator]);
	free(data.matrix);
	free(data.str);
	*stack_a = a;
	return (0);
}
