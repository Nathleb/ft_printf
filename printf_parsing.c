/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:35:51 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/02 23:38:27 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


//"cspdiuxX%"
//"-0.*"
//% [flags] [width] [.prec] [F|N|h|l|L] type_char
// 0 for d, i, o, u, x, X
/*typedef struct	s_flags
{
	t_bool	zero_pad;
	t_bool	left_align;
	int		width;
	int		precision;
	char	conv_type;
}				t_flags;
*/

int	ft_atoi(const char *nptr)
{
	long long int	sign;
	long long int	ret;
	unsigned int	i;

	i = 0;
	sign = 1;
	ret = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r' ||
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	ret *= sign;
	return ((int)ret);
}


char	*parse_width(char *str, t_flags *flags, va_list ap)
{
	if (*str >= '1' && *str <= '9')
		flags->width = ft_atoi(str);
	else if (*str == '*')
	{
		str++;
		flags->width = va_arg(ap, int);
	}
	else
		flags->width = -1;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

char	*parse_precision(char *str, t_flags *flags, va_list ap)
{
	if (*str == '.')
	{
		str++;
		if (*str >= '1' && *str <= '9')
			flags->precision = ft_atoi(str);
		else if (*str == '*')
			flags->precision = va_arg(ap, int);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	else
		flags->precision = -1;
	return (str);
}

char	*parse_flags(char *str, t_flags *flags)
{
	while (*str == '0' || *str == '-')
	{
		if (*str == '0')
			flags->zero_pad = 1;
		else
			flags->left_align = 1;
		str++;
	}
	return (str);
}

t_flags	printf_parse(char *str, va_list ap)
{
	t_flags flags;

	flags.zero_pad = 0;
	flags.left_align = 0;
	str = parse_flags(str, &flags);
	str = parse_width(str, &flags, ap);
	str = parse_precision(str, &flags, ap);
	flags.conv_type = *str;
	return (flags);
}

void test_valist(char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	printf("init");
	t_flags flags = printf_parse(str, ap);
	printf("0pad %d\n", flags.zero_pad);
	printf("lalign %d\n", flags.left_align);
	printf("width %d\n", flags.width);
	printf("precision %d\n", flags.precision);
	printf("conv_type %c\n", flags.conv_type);
	va_end(ap);
}

int	main()
{
	char *str = "0-*.*d";
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	test_valist(str, i2 ,i3,i4);
	return (0);
}

