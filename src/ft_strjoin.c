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
	t_pars	pars;
	char	*res;

	pars.i = -1;
	pars.res_len = 0;
	while (--ac)
		pars.res_len += ft_strlen(av[ac]) + 1;
	res = (char *)malloc(sizeof(char) * pars.res_len);
	if (!res)
		error_exit();
	while (av[++ac])
	{
		pars.j = -1;
		while (av[ac][++pars.j])
			res[++pars.i] = av[ac][pars.j];
		if (pars.j == 0)
			error_exit();
		if (av[ac + 1])
			res[++pars.i] = ' ';
	}
	res[++pars.i] = '\0';
	check_strjoin(pars, res);
	return (res);
}

int	check_strjoin(t_pars pars, char *res)
{
	pars.i = -1;
	pars.j = -1;
	while (res[++pars.i])
		if (res[pars.i] != ' ')
			pars.j = 1;
	if (pars.j == -1)
		error_exit();
	return (0);
}
