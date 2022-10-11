#include "../inc/push_swap.h"

void	pchar(char c)
{
	write(1, &c, 1);
}

void	pstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		pchar(str[i]);
}

void	print_number(int nbr)
{
	long int	nb;
	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		pchar('-');
	}
	if (nb > 9)
		print_number(nb / 10);
	pchar(nb % 10 + '0');
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
