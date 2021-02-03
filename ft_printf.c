/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:57:18 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/03 21:26:41 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_pfdisplay(char *str, va_list ap)
{
	int ret;
	t_flags flags;

	flags = printf_parse(str, ap);
	if (flags.conv_type = )

	free(str);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	i;
	unsigned int	j;
	int				ret;

	va_start(ap, str);
	ret = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] != '%' && ret++ && str[i])
			write(1, &str[i++], 1);
		if (str[i] == '%')
		{
			j = ++i;
			while (str[i] && !ft_isin("cspdiuxX%", str[i]))
				i++;
			if (ft_isin("cspdiuxX%", str[i]))
				ret += ft_pfdisplay(ft_substr(str, j, i - j), ap);
		}
	}
	va_end(ap);
	return (ret);
}

int main(int argc, char **argv)
{
	(void)argc;
	ft_printf(argv[1]);
	return 0;
}
