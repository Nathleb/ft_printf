/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:35:51 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/16 21:44:40 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*parse_width(char *str, t_flags *flags, va_list *ap)
{
	if (*str >= '1' && *str <= '9')
		flags->width = ft_atoi(str);
	else if (*str == '*')
	{
		str++;
		flags->width = va_arg(*ap, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->left = 1;
		}
	}
	else
		flags->width = -1;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

char	*parse_precision(char *str, t_flags *flags, va_list *ap)
{
	if (*str == '.')
	{
		str++;
		if (*str >= '0' && *str <= '9')
			flags->prec = ft_atoi(str);
		else if (*str == '*')
		{
			str++;
			flags->prec = va_arg(*ap, int);
			if (flags->prec < 0)
				flags->prec = -1;
		}
		else
			flags->prec = 0;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	else
		flags->prec = -1;
	return (str);
}

char	*parse_flags(char *str, t_flags *flags)
{
	while (*str == '0' || *str == '-')
	{
		if (*str == '0')
			flags->zero = 1;
		else
			flags->left = 1;
		str++;
	}
	return (str);
}

t_flags	printf_parse(char *str, va_list *ap)
{
	t_flags flags;

	flags.zero = 0;
	flags.left = 0;
	str = parse_flags(str, &flags);
	str = parse_width(str, &flags, ap);
	str = parse_precision(str, &flags, ap);
	flags.conv_type = *str;
	if (ft_isin("cspdiuxX%", flags.conv_type))
		return (flags);
	flags.conv_type = '0';
	return (flags);
}
