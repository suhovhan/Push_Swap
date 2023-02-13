/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:35:50 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/30 17:35:56 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bonus.h"

int	check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '\n' || line[i] != 'p' \
			|| line[i] != 'a' || line[i] != 'b' \
			|| line[i] != 's' || line[i] != 'r' \
			|| line[i] != 'o' || line[i] != 'E' \
			|| line[i] != 'D')
			error_exit();
	return (0);
}
