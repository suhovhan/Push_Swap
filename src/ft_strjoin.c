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
	res = (char *)malloc(sizeof(char) * res_len - 1);
	if (!res)
		error_exit("!res\n");
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