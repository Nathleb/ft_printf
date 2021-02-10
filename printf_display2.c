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
	int len;
	int prec;

	prec = flags.prec;
	ret = 0;
	if ((s = malloc(1)) && !(s[0] = '\0') && (s = ft_litoa_base(nb, base, s)))
	{
		len = (nb > 0 || flags.prec == -1) ? (int)ft_strlen(s) : 0;
		flags.prec = (flags.prec == -1) ? 0 : flags.prec;
		flags.zero = (flags.prec > 0) ? 0 : flags.zero;
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
	int len;
	int prec;

	ret = 0;
	prec = flags.prec;
	if (nb == 0 && flags.prec == 0)
	{
		ret += (!flags.left) ? padnbr(flags, flags.width - 2) : 0;
		ret += write(1, "0x", 2);
		ret += (flags.left) ? padnbr(flags, flags.width - 2) : 0;
		return (ret);
	}
	if ((s = malloc(1)) && !(s[0] = '\0') && (s = ft_litoa_base(nb, base, s)))
	{
		len = (int)ft_strlen(s) + 2;
		ret += (!flags.left) ? padnbr(flags, flags.width - ft_max(len, flags.prec)) : 0;
		ret += write(1, "0x", 2);
		while (--prec >= (int)len - 2)
			ret += write(1, "0", 1);
		ret += write(1, s, len);
		ret += (flags.left) ? padnbr(flags, flags.width - ft_max(len, flags.prec)) : 0;
		free(s);
	}
	return (ret);
}
