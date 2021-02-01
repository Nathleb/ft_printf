/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:40:07 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/01 17:27:38 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//"cspdiuxX%"
//"-0.*"
//% [flags] [width] [.prec] [F|N|h|l|L] type_char
// 0 for d, i, o, u, x, X
#include "libftprintf.h"

void	ft_initflags(t_flags *flags)
{
	flags->pad_size = 0;
	flags->zero_pad = 0;
	flags->left_align = 0;
	flags->width = 0;
	flags->precision=0;
}

t_flags	*ft_pfparse(char *str)
{
	t_flags flags;
	int i;

	i = 0;
	
	return (flags);
}

void	ft_displayvar(char *str, va_list ap)
{
	t_flags flags;
	int		lenstr;

	lenstr = ft_strlen(str);
	flags = ft_pfparse(str);
	if (str[lenstr-1] == 'd' || str[lenstr-1] == 'i')

	if (str[lenstr-1] == 'x' || str[lenstr-1] == 'X')

	if (str[lenstr-1] == 'u')

	if (str[lenstr-1] == 's')

	if (str[lenstr-1] == 'c')
		
	if (str[lenstr-1] == 'p')

	free(str);
}

void	ft_pfloop(char *str, va_list ap)
{
	unsigned int i;
	unsigned int j;
	char *conv;

	conv = "cspdiuxX%";
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i++], 1);
		else
		{
			j = ++i;
			while (!ft_chr(conv, str[i]))
				i++;
			ft_displayvar(ft_substr(str, j, i-j), ap);
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	
	va_end(ap); 
}
