#include "libftprintf.h"

void test_va(va_list ap)
{
	printf("%d\n", va_arg(ap, int));
}

void test_valist(int i, ...)
{
	va_list ap;

	va_start(ap, i);
	printf("%d\n", va_arg(ap, int));
	test_va(ap);
	printf("%d\n", va_arg(ap, int));
	printf("%d\n", va_arg(ap, int));
	va_end(ap);
}

int	main()
{
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	test_valist(i1, i2 ,i3,i4);
	return (0);
}
