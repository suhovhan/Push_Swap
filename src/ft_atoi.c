/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:37:12 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:37:15 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long int	ft_atoi(char *str)
{
	int				i;
	long int		res;
	int				neg;

	res = 0;
	neg = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				neg *= -1;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += str[i] - '0';
		}
	}
	if ((res * neg) < -2147483648 || (res * neg) > 2147483647)
		error_exit();
	return (res * neg);
}
