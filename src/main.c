/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:37:23 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:37:25 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_pars		pars;
	int			nbr;

	chek_num(ac, av);
	b = NULL;
	pars.iterator = -1;
	pars.str = ft_strjoin(ac, av);
	pars.matrix = ft_split(pars.str, ' ');
	while (pars.matrix[++pars.iterator])
	{
		check_right_num(pars.matrix[pars.iterator]);
		nbr = ft_atoi(pars.matrix[pars.iterator]);
		append(&a, nbr);
	}
	check_duble(&a);
	get_index(&a);
	run_algo(&a, &b);
	pars.iterator = -1;
	while (pars.matrix[++pars.iterator])
		free(pars.matrix[pars.iterator]);
	free(pars.matrix);
	free(pars.str);
	return (0);
}
