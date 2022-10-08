#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "push_swap_structs.h"

//............utils.c...........

int			ft_strlen(char *str);
int			getwordcount(char *s);
char		*fillword(char *s, int startindex, int len);
char		**ft_split(char *s);
void		pchar(char c);
void		pstr(char *str);
void		print_number(int nbr);
long int	ft_atoi(char *str);

//............utils.c...........

//............error.c...........

int		chek_num(int ac, char **av);
int		count_words(char *s);
int		check_right_num(char *s);
int		check_duble(t_stack **nums);
void	error_exit(char *error);
char	*ft_strjoin(int ac, char **av);

//............error.c...........

//........str_functions.c.......

int	append(t_stack **head_ref, int new_data);
int	pa(t_stack **a, t_stack **b);
int	pb(t_stack **head_a, t_stack **head_b);
int	ss(t_stack **head_a, t_stack **head_b);
int	rr(t_stack **head_a, t_stack **head_b);
int	rrr(t_stack **head_a, t_stack **head_b);
int	sa(t_stack **head_a);
int	sb(t_stack **head_b);
int	ra(t_stack **head_a);
int	rb(t_stack **head_b);
int	rra(t_stack **head_a);
int	rrb(t_stack **head_b);

//........str_functions.c.......


#endif