#include "philo.h"

static
int	ft_intlen(unsigned long long int n)
{
	int	result;

	result = 0;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char	*itoa(unsigned long long int n)
{
	int		len;
	char	*result;

	len = ft_intlen(n);
	result = malloc(len + 1);
	*(result + len) = 0;
	if (!result)
		return (0);
	while (len > 0)
	{
		*(result + len - 1) = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (result);
}
