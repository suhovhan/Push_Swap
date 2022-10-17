/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:39:11 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:51:05 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H

typedef struct s_stack
{
	int				nb;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_algo
{
	int	iterator;
	int	counter;
	int	n;
}				t_algo;

typedef struct s_vars
{
	int		len;
	int		min;
	int		i;
}				t_vars;

typedef struct s_pars
{
	int		iterator;
	char	*str;
	char	**matrix;
}				t_pars;

#endif
