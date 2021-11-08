#include "ft_printf.h"

int	main(void)
{
	//int	i;
	//int	j;
	char *str = "YEETTT";

	printf("printf:: %%: %% | i: %i | d: %d | s: %s | c: %c | u: %u | x: %x | X: %X | p: %p  \n", 42, 42, "YEET", 'Z', UINT_MAX, UINT_MAX, 42, str);
	//printf("%x\n", 50);
	ft_printf("ft_printf:: %%: %% | i: %i | d: %d | s: %s | c: %c | u: %u | x: %x | X: %X | p: %p  \n", 42, 42, "YEET", 'Z', UINT_MAX, UINT_MAX, 42, str);
	//ft_printf("%x\n", 50);
	return (0);
}
