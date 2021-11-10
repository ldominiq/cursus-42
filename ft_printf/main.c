#include "ft_printf.h"

int	main(void)
{
	int	i;
	int	j;
	//char *str = "YEETTT";

	//i = printf("printf:: %%: %% | i: %i | d: %d | s: %s | c: %c | u: %u | x: %x | X: %X | p: %p  \n", 42, 42, "YEET", 'Z', UINT_MAX, UINT_MAX, 42, str);
	i = printf(" %p ", NULL);
	printf("%i\n", i);
	//j = ft_printf("ft_printf:: %%: %% | i: %i | d: %d | s: %s | c: %c | u: %u | x: %x | X: %X | p: %p  \n", 42, 42, NULL, 'Z', UINT_MAX, UINT_MAX, 42, str);
	j = ft_printf(" %p ", NULL);
	printf("%i\n", j);
	return (0);
}
