#include "libft.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_intlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[len--] = 0;
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}