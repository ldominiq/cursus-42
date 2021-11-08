#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	while (++i < count * size)
		ptr[i] = 0;
	return (ptr);
}

void	ft_puthex_fd(unsigned int n, int upper, int fd)
{
	unsigned int	tmp;
	int				i;
	char			*hex;

	i = 0;
	if (n != 0)
	{
		hex = ft_calloc(sizeof(char), 9);
		while (n != 0)
		{
			tmp = n % 16;
			if (tmp > 9)
				hex[i] = (char)(tmp + upper);
			else
				hex[i] = (char)(tmp + 48);
			n = n / 16;
			i++;
		}
		hex[i] = 0;
		while (--i >= 0)
			ft_putchar_fd(hex[i], fd);
		free(hex);
	}
	else
		ft_putchar_fd('0', fd);
}

void	ft_putptr_fd(unsigned int n, int fd)
{
	unsigned int	tmp;
	int				i;
	char			*hex;

	i = 8;
	hex = ft_calloc(sizeof(char), 9);
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp > 9)
			hex[i] = (char)(tmp + 87);
		else
			hex[i] = (char)(tmp + 48);
		n = n / 16;
		i--;
	}
	while (i > 0)
		hex[i--] = '0';
	i = -1;
	while (++i <= 8)
		ft_putchar_fd(hex[i], fd);
	free(hex);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			ft_putchar_fd(s[i], fd);
	}
}
