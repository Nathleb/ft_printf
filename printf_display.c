/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:56:22 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/05 23:30:53 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putpad(t_flags flags, int pad_size)
{
	char c;
	int ret;

	ret = 0;
	c = ' ';
	if (flags.zero_pad && !flags.left_align)
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
	len = ft_strlen(s);
	if (flags.precision == -1)
		flags.precision =len;
	pad_size = flags.width - ft_min(flags.precision, len);
	if (!flags.left_align)
		ret += ft_putpad(flags, pad_size);
	ret += write(1, s, ft_min(flags.precision, len));
	if (flags.left_align)
		ret += ft_putpad(flags,pad_size);
	return (ret);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_putpad_nbr(t_flags flags, int pad_size)
{
	char c;
	int ret;

	ret = 0;
	c = ' ';
	if (flags.zero_pad && !flags.left_align)
		c = '0';
	while (pad_size-- > 0)
		ret += write(1, &c, 1);
	return (ret);
}

int	ft_display_unsignedint(t_flags flags, unsigned int nb, char *base)
{
	int pad_size;
	int ret;
	char *s;
	unsigned int len;

	ret = 0;
	if ((s = malloc(1)) && !(s[0] = '\0') && (s = ft_litoa_base(nb, base, s)))
	{
		len = ft_strlen(s);
		if (flags.precision == -1)
			flags.precision = 0;
		pad_size = flags.width - ft_max(len, flags.precision);
		if (flags.precision > len || flags.precision <= 0)
			flags.zero_pad = 0;
		if (!flags.left_align)
			ret += ft_putpad_nbr(flags, pad_size);
		while (flags.precision-- > len)
			ret += write(1, "0", 1);
		ret += write(1, s, len);
		if (flags.left_align)
			ret += ft_putpad_nbr(flags, pad_size);
		free(s);
	}
	return (ret);
}

int	ft_display_char(t_flags flags, char c)
{
	int pad_size;
	int ret;

	ret = 0;
	if (flags.precision == -1)
		flags.precision = 1;
	pad_size = flags.width - ft_min(flags.precision, 1);
	if (flags.left_align)
		ret += ft_putpad(flags, pad_size);
	ret += write(1, &c, ft_min(flags.precision, 1));
	if (!flags.left_align)
		ret += ft_putpad(flags,pad_size);
	return (ret);
}
