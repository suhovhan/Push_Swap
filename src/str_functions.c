/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:36:57 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:36:59 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	append(t_stack **head_ref, int new_data)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	new_node->nb = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
		*head_ref = new_node;
	else
	{
		last_node = *head_ref;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	return (0);
}

int	ft_list_len(t_stack *head_ref)
{
	t_stack	*tmp;
	int		len;

	tmp = head_ref;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	set_index(t_stack **head_ref)
{
	int		i;
	t_stack	*a;
	t_stack	*tmp;

	i = -1;
	a = *head_ref;
	tmp = a;
	tmp->index = 0;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	*head_ref = a;
	return (0);
}

int	index_manager(t_stack **head_ref, t_vars vars)
{
	t_stack	*tmp;

	tmp = *head_ref;
	while (vars.len--)
	{
		vars.min = 2147483647;
		while (tmp)
		{
			if (tmp->index == -1)
				if (tmp->nb < vars.min)
					vars.min = tmp->nb;
			tmp = tmp->next;
		}
		tmp = *head_ref;
		while (tmp)
		{
			if (tmp->nb == vars.min)
				tmp->index = ++vars.i;
			tmp = tmp->next;
		}
		tmp = *head_ref;
	}
	*head_ref = tmp;
	return (0);
}

int	get_index(t_stack **head_ref)
{
	t_stack	*ptr;
	t_stack	*tmp;
	t_vars	vars;

	vars.i = -1;
	ptr = *head_ref;
	tmp = *head_ref;
	vars.len = ft_list_len(ptr);
	set_index(&ptr);
	index_manager(&ptr, vars);
	*head_ref = ptr;
	return (0);
}
