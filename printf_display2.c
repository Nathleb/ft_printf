/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_display2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:56:22 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/17 21:09:22 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	padnbr(t_flags flags, int pad_size)
{
	char	c;
	int		ret;

	ret = 0;
	c = ' ';
	if (flags.zero && !flags.left)
		c = '0';
	while (pad_size-- > 0)
		ret += write(1, &c, 1);
	return (ret);
}

int	ft_display_ui(t_flags flags, unsigned int nb, char *base)
{
	int		ret;
	char	*s;
	int		len;
	int		prec;

	prec = flags.prec;
	ret = 0;
	s = ft_calloc(1, sizeof(char));
	if (s && (s = ft_ulitoa_b(nb, base, s)))
	{
		len = (nb > 0 || flags.prec == -1) ? (int)ft_strlen(s) : 0;
		flags.zero = (flags.prec >= 0) ? 0 : flags.zero;
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

int	ft_display_p(t_flags flags, unsigned long int nb, char *base)
{
	int		ret;
	char	*s;
	int		len;
	int		prec;

	ret = 0;
	prec = flags.prec;
	s = ft_calloc(1, sizeof(char));
	if (s && (s = ft_ulitoa_b(nb, base, s)))
	{
		len = (int)ft_strlen(s) + 2;
		if (nb == 0 && flags.prec == 0)
			len = 2;
		flags.pad_size = flags.width - ft_max(len, flags.prec);
		ret += (!flags.left) ? padnbr(flags, flags.pad_size) : 0;
		ret += write(1, "0x", 2);
		while (--prec >= (int)len - 2)
			ret += write(1, "0", 1);
		ret += write(1, s, len - 2);
		ret += (flags.left) ? padnbr(flags, flags.pad_size) : 0;
		free(s);
	}
	return (ret);
}

int	ft_display_int(t_flags flags, int nb)
{
	int		ret;
	char	*s;
	int		prec;
	int		pad;

	ret = 0;
	if (nb >= 0)
		return (ft_display_ui(flags, (unsigned int)nb, DEC));
	s = ft_calloc(1, sizeof(char));
	if (s && (s = ft_litoa_base(nb, DEC, s)))
	{
		flags.zero = (flags.prec >= 0) ? 0 : flags.zero;
		if (flags.prec == -1 && flags.zero == 1 && flags.left == 0)
			flags.prec = flags.width - 1;
		prec = flags.prec;
		pad = flags.width - 1 - ft_max((int)ft_strlen(s) - 1, flags.prec);
		ret += (!flags.left) ? padnbr(flags, pad) : 0;
		ret += write(1, s, 1);
		while (--prec >= (int)ft_strlen(s) - 1)
			ret += write(1, "0", 1);
		ret += write(1, s + 1, (int)ft_strlen(s) - 1);
		ret += (flags.left) ? padnbr(flags, pad) : 0;
		free(s);
	}
	return (ret);
}
