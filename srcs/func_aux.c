#include "../minitalk.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

int	ft_atoi(const char *nptr)
{
	unsigned char	*ptr;
	int				sign;
	long long		rsl;

	ptr = (unsigned char *)nptr;
	if (!nptr)
		return (0);
	sign = 1;
	rsl = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		rsl = ((rsl * 10) + (*ptr - '0'));
		ptr++;
	}
	return (rsl * sign);
}