/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:35:51 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/02 22:50:21 by nle-biha         ###   ########.fr       */
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

char	*parse_width(char *str, t_flags *flags, va_list ap)
{
	if (*str >= '1' && *str <= '9')
		flags.width = ft_atoi(str);
	else if (*str == '*')
		flags.width = va_arg(ap, int);
	else
		flags.width = -1;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

char	*parse_precision(char *str, t_flags *flags, va_list ap)
{
	if (*str == '.')
	{
		str++;
		if (str >= '1' && str[i] <= '9')
			flags.precision = ft_atoi(str);
		else if (*str == '*')
			flags.precision = va_arg(ap, int);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	else
		flags.precision = -1;
	return (str);
}

char	*parse_flags(char *str, t_flags *flags)
{
	while (*str)
	{
		while (*str == '0' || *str == '-')
		{
			if (*str == '0')
				flags.zero_pad = 1;
			else
				flags.left_align = 1;
			str++;
		}
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
	str = parse_prec(str, &flags, ap);
	flags.conv_type = *str;
}
