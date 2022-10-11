#include "../inc/push_swap.h"

long int	ft_atoi(char *str)
{
	int				i;
	long int		res;
	int				neg;
	
	res = 0;
	neg = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				neg *= -1;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += str[i] - '0';
		}
	}
	if ((res * neg) < -2147483648 || (res * neg) > 2147483647)
		error_exit("Int is too long");
	return (res * neg);
}