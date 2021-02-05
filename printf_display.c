/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:56:22 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/05 21:48:18 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putpad(t_flags flags, int pad_size)
{
	char c;
	int ret;

	ret = 0;
	c = ' ';
	if (flags.zero_pad && !flags.left_align && ft_isin("diouxX",flags.conv_type))
		c = '0';
	while (pad_size-- > 0)
	{
		ret++;
		write(1, &c, 1);
	}
	return (ret);
}

int	ft_display_string(t_flags flags, char *s)
{
	int pad_size;
	int ret;

	ret = 0;
	if (flags.precision == -1)
		flags.precision = ft_strlen(s);
	pad_size = flags.width - ft_min(flags.precision, ft_strlen(s));
	if (!flags.left_align)
		ret += ft_putpad(flags, pad_size);
	write(1, s, ft_min(flags.precision, ft_strlen(s)));
	ret += ft_min(flags.precision, ft_strlen(s)); 
	if (flags.left_align)
		ret += ft_putpad(flags,pad_size);
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
	write(1, &c, ft_min(flags.precision, 1));
	ret += ft_min(flags.precision, 1); 
	if (!flags.left_align)
		ret += ft_putpad(flags,pad_size);
	return (ret);
}
