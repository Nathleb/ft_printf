/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:56:22 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/06 19:22:40 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putpad(t_flags flags, int pad_size)
{
	char c;
	int ret;

	ret = 0;
	c = ' ';
	if (flags.zero && !flags.left)
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
	if (flags.prec == -1)
		flags.prec = len;
	pad_size = flags.width - ft_min(flags.prec, len);
	if (!flags.left)
		ret += ft_putpad(flags, pad_size);
	ret += write(1, s, ft_min(flags.prec, len));
	if (flags.left)
		ret += ft_putpad(flags, pad_size);
	return (ret);
}

int	padnbr(t_flags flags, int pad_size)
{
	char c;
	int ret;

	ret = 0;
	c = ' ';
	if (flags.zero && !flags.left)
		c = '0';
	while (pad_size-- > 0)
		ret += write(1, &c, 1);
	return (ret);
}


int	ft_display_unsignedint(t_flags flags, unsigned int nb, char *base)
{
	int ret;
	char *s;
	unsigned int len;
	int prec;

	prec = flags.prec;
	ret = 0;
	if ((s = malloc(1)) && !(s[0] = '\0') && (s = ft_litoa_base(nb, base, s)))
	{
		len = ft_strlen(s);
		flags.prec = (flags.prec == -1) ? 0 : flags.prec;
		flags.zero = (flags.prec > len || flags.prec <= 0) ? 0 : flags.zero;
		if (!flags.left)
			ret += padnbr(flags, flags.width - ft_max(len, flags.prec));
		while (--prec >= (int)len)
			ret += write(1, "0", 1);
		ret += write(1, s, len);
		if (flags.left)
			ret += padnbr(flags, flags.width - ft_max(len, flags.prec));
		free(s);
	}
	return (ret);
}

int	ft_display_pointer(t_flags flags, unsigned int nb, char *base)
{
	int ret;
	char *s;
	unsigned int len;
	int prec;

	if (flags.prec == -1 && (flags.prec = flags.width) == flags.width)
		prec = flags.prec - 2;
	else
		prec = flags.prec;
	ret = 0;
	if ((s = malloc(1)) && !(s[0] = '\0') && (s = ft_litoa_base(nb, base, s)))
	{
		len = ft_strlen(s) + 2;
		flags.zero = (flags.prec > len || flags.prec <= 0) ? 0 : flags.zero;
		ret += (!flags.left) ? padnbr(flags, flags.width - ft_max(len, flags.prec)) : 0; 
		ret += write(1, "0x", 2); 
		while (--prec >= (int)len - 2)
			ret += write(1, "0", 1);
		ret += write(1, s, len - 2);
		ret += (flags.left) ? padnbr(flags, flags.width - ft_max(len, flags.prec)) : 0;
		free(s);
	}
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
	if (flags.left)
		ret += ft_putpad(flags, pad_size);
	ret += write(1, &c, ft_min(flags.prec, 1));
	if (!flags.left)
		ret += ft_putpad(flags,pad_size);
	return (ret);
}