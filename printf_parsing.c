/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:35:51 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/04 02:37:30 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	if (ft_isin("cspdiuxX%", flags.conv_type))
		return (flags);
	flags.conv_type = '0';
	return (flags);
	
}
