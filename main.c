#include "libftprintf.h"

int	main()
{
	char *returned = malloc(1);
	returned = ft_litoa_base(-7387, "0123456789", returned); 
	printf("%s", returned);
	free(returned);
	return (0);
}
