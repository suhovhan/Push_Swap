/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:36:45 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:36:47 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	chek_num(int ac, char **av)
{
	int	i;
	int	j;

	i = ac - 2;
	if (ac < 2)
		exit(0);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ' \
			&& av[i][j] != '-' && av[i][j] != '+')
				error_exit();
	}
	return (0);
}

int	check_right_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i] || s[i] < '0' || s[i] > '9')
	{
		free(s);
		error_exit();
	}
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] && s[i] != ' ')
	{
		free(s);
		error_exit();
	}
	return (0);
}

int	check_duble(t_stack **nums)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (*nums == NULL || nums == NULL)
		free_and_exit(nums);
	ptr = *nums;
	while (ptr)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (ptr->nb == tmp->nb)
			{
				write(2, "Error\n", 6);
				free_and_exit(nums);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	return (0);
}
