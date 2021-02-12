/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:56:22 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/07 17:04:09 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putspace(t_flags flags, int pad_size)
{
	char c;
	int ret;

	ret = 0;
	c = ' ';
	if (flags.conv_type == '%' && flags.zero == 1 && flags.left == 0)
		c = '0';
	while (pad_size-- > 0)
		ret += write(1, &c, 1);
	return (ret);
}

int	ft_display_string(t_flags flags, char *s)
{
	int pad_size;
	int ret;
	unsigned int len;

	ret = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags.prec == -1)
		flags.prec = len;
	pad_size = flags.width - ft_min(flags.prec, len);
	if (!flags.left)
		ret += ft_putspace(flags, pad_size);
	ret += write(1, s, ft_min(flags.prec, len));
	if (flags.left)
		ret += ft_putspace(flags, pad_size);
	return (ret);
}

int	ft_display_char(t_flags flags, char c)
{
	int pad_size;
	int ret;

	ret = 0;
	if (flags.prec == -1)
		flags.prec = 1;
	pad_size = flags.width - ft_min(flags.prec, 1);
	if (!flags.left)
		ret += ft_putspace(flags, pad_size);
	ret += write(1, &c, ft_min(flags.prec, 1));
	if (flags.left)
		ret += ft_putspace(flags, pad_size);
	return (ret);
}
