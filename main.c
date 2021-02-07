
#include "libftprintf.h"

int main(int argc, char **argv)
{
	(void)argc;
	char c = 'c';
	char *s = "0123456789";
	unsigned int e = 4543543;

	(void)c;
	(void)s;
	(void)e;
	printf("\n%d\n",ft_printf(argv[1],s,s));
	printf("\n\n");
	printf("\n%d\n",printf(argv[1],s,s));
	return 0;
}

