#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

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


#endif