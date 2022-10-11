#include "../inc/push_swap.h"

void	error_exit(char *error)
{
	pstr("ERROR:  ");
	pstr(error);
	pchar('\n');
	exit(0);
}

int	chek_num(int ac, char **av)
{
	int	i;
	int	j;

	i = ac - 2;
	if (ac < 2)
		error_exit("there is no arguments");
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ' \
			&& av[i][j] != '-' && av[i][j] != '+')
				error_exit("some arguments aren’t integers");
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
		error_exit("there was non logic int");
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] && s[i] != ' ')
		error_exit("there was non logic int");
	return (0);
}

int	check_duble(t_stack **nums)
{
	t_stack	*ptr;
	t_stack	*tmp;
	if (*nums == NULL || nums == NULL)
		exit(0);
	ptr = *nums;
	while (ptr)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (ptr->nb == tmp->nb)
				error_exit("there was dublicate");
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	return (0);
}