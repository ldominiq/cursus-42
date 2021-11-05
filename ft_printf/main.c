#include "ft_printf.h"

int	main(void)
{
	//int	i;
	//int	j;
	char *str = "YEE";

	printf("printf:: i: %i | d: %d | s: %s | c: %c | %%: %% | u: %u | p: %p | x: %x | X: %X\n", 42, 42, "YEET", 'Z', 5, str, 42, 42);
	//printf("%d\n", i);
	ft_printf("ft_printf:: i: %i | d: %d | s: %s | c: %c | %%: %% | u: %u | p: %p | x: %x | X: %X\n", 42, 42, "YEET", 'Z', 5, str, 42, 42);
	//ft_printf("%d\n", j);
	return (0);
}
