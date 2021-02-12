/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:57:18 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/07 01:23:17 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_pfdisplay(char *str, va_list ap)
{
	int ret;
	t_flags flags;

	ret = 0;
	flags = printf_parse(str, ap);
	free(str);
	if (flags.conv_type == 's')
		ret += ft_display_string(flags, va_arg(ap, char *));
	if (flags.conv_type == 'c')
		ret += ft_display_char(flags, va_arg(ap, int));
	if (flags.conv_type == '%')
		ft_display_char(flags, '%');
	if (flags.conv_type == 'x')
		ret += ft_display_unsignedint(flags, va_arg(ap, unsigned int),"0123456789abcdef");
	if ( flags.conv_type == 'X')
		ret += ft_display_unsignedint(flags, va_arg(ap, unsigned int),"0123456789ABCDEF");
	if (flags.conv_type == 'u')
		ret += ft_display_unsignedint(flags, va_arg(ap, unsigned int),"0123456789");
	if (flags.conv_type == 'p')
		ret += ft_display_pointer(flags, (unsigned long int)va_arg(ap, void *),"0123456789abcdef");
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
			while (str[i] && !ft_isin("cspdiuxX%", str[i]))
				i++;
			if (ft_isin("cspdiuxX%", str[i]))
				ret += ft_pfdisplay(ft_substr(str, j, ++i - j), ap);
		}
	}
	va_end(ap);
	return (ret);
}
