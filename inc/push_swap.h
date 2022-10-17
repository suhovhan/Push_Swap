/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:39:20 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:49:39 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./push_swap_structs.h"

int			ft_strlen(char *str);
int			getwordcount(char *s);
char		*fillword(char *s, int start_index, int len);
char		**ft_split(char *s);
void		pchar(char c);
void		pstr(char *str);
void		print_number(int nbr);
long int	ft_atoi(char *str);
int			chek_num(int ac, char **av);
int			count_words(char *s);
int			check_right_num(char *s);
int			check_duble(t_stack **nums);
int			free_and_exit(t_stack **stack_a);
void		error_exit(void);
char		*ft_strjoin(int ac, char **av);
int			append(t_stack **head_ref, int new_data);
int			ft_list_len(t_stack *head_ref);
int			index_manager(t_stack **head_ref, t_vars vars);
int			set_index(t_stack **head_ref);
int			get_index(t_stack **head_ref);
int			pa(t_stack **a, t_stack **b);
int			pb(t_stack **head_a, t_stack **head_b);
int			ss(t_stack **head_a, t_stack **head_b);
int			rr(t_stack **head_a, t_stack **head_b);
int			rrr(t_stack **head_a, t_stack **head_b);
int			sa(t_stack **head_a);
int			sb(t_stack **head_b);
int			ra(t_stack **head_a);
int			rb(t_stack **head_b);
int			rra(t_stack **head_a);
int			rrb(t_stack **head_b);
int			is_sorted(t_stack *a);
int			algo2(t_stack **a);
int			algo3(t_stack **stack_a);
int			algo4(t_stack **stack_a, t_stack **stack_b);
int			algo5(t_stack **stack_a, t_stack **stack_b);
int			comb_algo4(t_stack **stack_a, t_stack **stack_b);
int			comb_algo5(t_stack **stack_a, t_stack **stack_b);
int			run_algo(t_stack **stack_a, t_stack **stack_b);
int			sort_stack(t_stack **stack_a, t_stack **stack_b);
int			max_node_to_start(t_stack **stack_b, t_algo data);
int			max_node_to_start(t_stack **stack_b, t_algo data);
t_algo		algo_meneger(t_stack **stack_a, t_stack **stack_b, t_algo data);
t_algo		to_stack_b(t_stack **stack_a, t_stack **stack_b);

#endif
