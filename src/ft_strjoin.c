/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:36:23 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:36:25 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strjoin(int ac, char **av)
{
	char	*res;
	int		res_len;
	int		i;
	int		j;

	i = -1;
	res_len = 0;
	while (--ac)
		res_len += ft_strlen(av[ac]) + 1;
	res = (char *)malloc(sizeof(char) * res_len);
	if (!res)
		error_exit();
	while (av[++ac])
	{
		j = -1;
		while (av[ac][++j])
			res[++i] = av[ac][j];
		if (av[ac + 1])
			res[++i] = ' ';
	}
	res[++i] = '\0';
	return (res);
}
