/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:57:18 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/17 19:29:47 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pfdisplay(char *str, va_list *ap)
{
	int		ret;
	t_flags	flags;

	ret = 0;
	flags = printf_parse(str, ap);
	free(str);
	if (flags.conv_type == 's')
		ret += ft_display_string(flags, va_arg(*ap, char *));
	if (flags.conv_type == 'c')
		ret += ft_display_char(flags, va_arg(*ap, int));
	if (flags.conv_type == '%')
		ret += ft_display_char(flags, '%');
	if (flags.conv_type == 'x')
		ret += ft_display_unsignedint(flags, va_arg(*ap, unsigned int), HE);
	if (flags.conv_type == 'X')
		ret += ft_display_unsignedint(flags, va_arg(*ap, unsigned int), HEX);
	if (flags.conv_type == 'u')
		ret += ft_display_unsignedint(flags, va_arg(*ap, unsigned int), DEC);
	if (flags.conv_type == 'p')
		ret += ft_display_p(flags, (unsigned long int)va_arg(*ap, void *), HE);
	if (flags.conv_type == 'i' || flags.conv_type == 'd')
		ret += ft_display_int(flags, va_arg(*ap, int));
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	i;
	unsigned int	j;
	int				ret;

	va_start(ap, str);
	ret = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			ret += write(1, &str[i++], 1);
		if (str[i] == '%')
		{
			j = ++i;
			while (str[i] && !ft_isin(CONV, str[i]))
				i++;
			if (ft_isin(CONV, str[i]))
				ret += ft_pfdisplay(ft_substr(str, j, ++i - j), &ap);
		}
	}
	va_end(ap);
	return (ret);
}
